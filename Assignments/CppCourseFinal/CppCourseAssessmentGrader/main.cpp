#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Scheduler.h"
#include "ITasklet.h"
#include <memory>
#include <chrono>

using namespace std;
using namespace chrono;

class TestTasklet : public ITasklet {
public:
	TestTasklet(const std::string &expected_string, const long &expected_tasklet_id) : 
		expected_string(expected_string), expected_tasklet_id(expected_tasklet_id) { 
	}

	long get_tasklet_id() const override {
		return expected_tasklet_id;
	}

	std::string execute() override {
		executed = true;
		return expected_string;
	}

	bool was_executed() {
		return executed;
	}
private:
	std::string expected_string;
	long expected_tasklet_id;
	bool executed = false;
};

TEST_CASE("SchedulerInserts", "Scheduler can insert tasklets") {
	Scheduler scheduler;
	auto time = std::chrono::system_clock::now();
	auto tasklet = make_shared<TestTasklet>("result", 1);

	scheduler.schedule_tasklet(time, tasklet);

	auto result = scheduler.next_tasklet();
	REQUIRE(result.first == time);
	REQUIRE(result.second == tasklet);
}

TEST_CASE("SchedulerExecutes", "Scheduler can execute tasklets in sequence") {
	Scheduler scheduler;
	auto time_1 = system_clock::now();
	auto time_2 = time_1 + milliseconds(100);
	auto time_3 = time_2 + milliseconds(100);
	auto tasklet_1 = make_shared<TestTasklet>("result 1", 1);
	auto tasklet_2 = make_shared<TestTasklet>("result 2", 2);
	auto tasklet_3 = make_shared<TestTasklet>("result 3", 3);

	scheduler.schedule_tasklet(time_1, tasklet_1);
	scheduler.schedule_tasklet(time_2, tasklet_2);
	scheduler.schedule_tasklet(time_3, tasklet_3);

	scheduler.run();

	REQUIRE(tasklet_1->was_executed());
	REQUIRE(tasklet_2->was_executed());
	REQUIRE(tasklet_3->was_executed());
}

TEST_CASE("SchedulerContainsTasks", "Scheduler correctly reports whether it contains tasks") {
	Scheduler scheduler;
	REQUIRE(!scheduler.contains_tasks());

	scheduler.schedule_tasklet(system_clock::now(), make_shared<TestTasklet>("result 1", 1));
	REQUIRE(scheduler.contains_tasks());

	scheduler.run();
	REQUIRE(!scheduler.contains_tasks());
}

TEST_CASE("SchedulerCallsHooks", "Scheduler correctly calls hooks on execution") {
	vector<long> hooked_tasklet_ids;

	Scheduler scheduler;
	auto time_1 = system_clock::now();
	auto time_2 = time_1 + milliseconds(100);
	auto tasklet_1 = make_shared<TestTasklet>("result 1", 1);
	auto tasklet_2 = make_shared<TestTasklet>("result 2", 2);

	scheduler.schedule_tasklet(time_1, tasklet_1);
	scheduler.schedule_tasklet(time_2, tasklet_2);
	scheduler.register_tasklet_hook([&hooked_tasklet_ids](const ITasklet &x) { hooked_tasklet_ids.push_back(x.get_tasklet_id()); });
	scheduler.run();

	REQUIRE(hooked_tasklet_ids[0] == 1);
	REQUIRE(hooked_tasklet_ids[1] == 2);
}

TEST_CASE("SchedulerCompletedTaskResult", "Scheduler correctly returns completed tasks") {
	Scheduler scheduler;
	auto time_1 = system_clock::now();
	auto time_2 = time_1 + milliseconds(100);
	auto tasklet_1 = make_shared<TestTasklet>("result 1", 1);
	auto tasklet_2 = make_shared<TestTasklet>("result 2", 2);

	scheduler.schedule_tasklet(time_1, tasklet_1);
	scheduler.schedule_tasklet(time_2, tasklet_2);

	scheduler.run();

	REQUIRE(scheduler.completed_tasklet_result(1) == "result 1");
	REQUIRE(scheduler.completed_tasklet_result(2) == "result 2");
}

TEST_CASE("SchedulerThrowsNextTasklet", "Scheduler throws exception when there is no next tasklet") {
	Scheduler scheduler;
	bool exception_thrown = false;
	try
	{
		scheduler.next_tasklet();
	}
	catch (exception e)
	{
		exception_thrown = string(e.what()) == "No tasklets assigned.";
	}
	REQUIRE(exception_thrown);
}

TEST_CASE("SchedulerThrowsCompletedTaskletResult", "Scheduler throws exception when there is no tasklet result") {
	Scheduler scheduler;
	bool exception_thrown = false;
	try
	{
		scheduler.completed_tasklet_result(1234);
	}
	catch (exception e)
	{
		exception_thrown = string(e.what()) == "Tasklet result not found.";
	}
	REQUIRE(exception_thrown);
}
