#include "Scheduler.h"
#include <thread>
#include <algorithm>

using namespace std;

void Scheduler::schedule_tasklet(timepoint scheduled_time, std::shared_ptr<ITasklet> tasklet) {
    // Store the tasklet in tasklets
}

std::pair<timepoint, std::shared_ptr<ITasklet>> Scheduler::next_tasklet() const {
    /*
    * @brief Returns the next_tasklet to run
    *
    * @throw std::exception if tasklets is empty.
    */
}

std::string Scheduler::completed_tasklet_result(long tasklet_id) const {
    /*
    * @brief returns the result for a tasklet that has run
    *
    * @throw std::exception if tasklet result not found.
    */
    return std::string();
}

void Scheduler::register_tasklet_hook(std::function<void(const ITasklet&)> hook) {
    /*
    * IMPLEMENT ME!
    * @brief stored the tasklet hook to be used later.
    */
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
    /*
    * IMPLEMENT ME!
    * @brief returns true if there are any tasklets to process.
    */
    return false;
}

void Scheduler::complete_next_tasklet() {
    /*
    * @details:
    * 1. should get "next_tasklet()"
    * 2. should call execute on the tasklet
    * 3. should store the result
    * 4. should pass the tasklet to all hooks
    * 5. should remove the tasklet from tasklets.
    */
}
