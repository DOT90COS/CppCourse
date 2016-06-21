#include "Scheduler.h"
#include <thread>
#include <algorithm>

using namespace std;

void Scheduler::schedule_tasklet(timepoint scheduled_time, std::shared_ptr<ITasklet> tasklet) {
    tasklets.insert({ scheduled_time, tasklet });
    //tasklets.insert(std::make_pair(scheduled_time, tasklet));
    //tasklets.insert(std::pair<timepoint, std::shared_ptr<ITasklet>>(scheduled_time, tasklet));
}

std::pair<timepoint, std::shared_ptr<ITasklet>> Scheduler::next_tasklet() const {
	if (tasklets.empty()) {
		throw exception("No tasklets assigned.");
	}
	return *tasklets.begin();
}

std::string Scheduler::completed_tasklet_result(long tasklet_id) const {
    if (results.find(tasklet_id) == results.end()) {
		throw exception("Tasklet result not found.");
	}
	return results.at(tasklet_id);
}

void Scheduler::register_tasklet_hook(std::function<void(const ITasklet&)> hook) {
	hooks.push_back(hook);
}

void Scheduler::run() {
	while (contains_tasks()) {
		this_thread::sleep_until(next_tasklet().first);
		while (contains_tasks() && next_tasklet().first < chrono::system_clock::now()) {
			complete_next_tasklet();
		}
	}
}

bool Scheduler::contains_tasks() const {
	return !tasklets.empty();
}
/*
* @details:
* 1. should get "next_tasklet()"
* 2. should call execute on the tasklet
* 3. should store the result
* 4. should pass the tasklet to all hooks
* 5. should remove the tasklet from tasklets.
*/
void Scheduler::complete_next_tasklet() {
	auto next_tasklet_pair = next_tasklet();
	auto tasklet = next_tasklet_pair.second;
	auto tasklet_id = tasklet->get_tasklet_id();
	auto tasklet_result = tasklet->execute();
    results[tasklet_id] = tasklet_result;
	//results.insert_or_assign(tasklet_id, tasklet_result);
    for (auto& x : hooks)
    {
        x(*tasklet);
    }
	//for_each(hooks.begin(), hooks.end(), [tasklet](auto hook) { hook(*tasklet); });
	tasklets.erase(next_tasklet_pair.first);
}
