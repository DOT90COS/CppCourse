#pragma once
#include "ITasklet.h"
#include <memory>
#include <map>
#include <functional>
#include <chrono>
#include<vector>

typedef std::chrono::system_clock::time_point timepoint;

class Scheduler {
public:
	~Scheduler() { }
    
    // Store the tasklet in tasklets
	void schedule_tasklet(timepoint, std::shared_ptr<ITasklet> tasklet);

    /*
    * @brief Returns the next_tasklet to run
    * 
    * @throw std::exception if tasklets is empty. 
    */
	std::pair<timepoint, std::shared_ptr<ITasklet>> next_tasklet() const;

    /*
    * @brief returns the result for a tasklet that has run
    * 
    * @throw std::exception if tasklet result not found. 
    */
	std::string completed_tasklet_result(long tasklet_id) const;

    /*
    * @brief stored the tasklet hook to be used later. 
    */
	void register_tasklet_hook(std::function<void(const ITasklet&)> hook);
	
    //given to you... Your welcome!
    void run();


    /*
    * @brief returns true if there are any tasklets to process.
    */
	bool contains_tasks() const;
private:
    /*
    * @details:
    * 1. should get "next_tasklet()"
    * 2. should call execute on the tasklet
    * 3. should store the result 
    * 4. should pass the tasklet to all hooks
    * 5. should remove the tasklet from tasklets.
    */
	void complete_next_tasklet();
	std::multimap<timepoint, std::shared_ptr<ITasklet>> tasklets;
	std::map<long, std::string> results;
	std::vector<std::function<void(const ITasklet&)>> hooks;
};
