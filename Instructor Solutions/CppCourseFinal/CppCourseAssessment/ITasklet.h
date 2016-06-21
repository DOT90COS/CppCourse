#pragma once
#include <string>

class ITasklet {
public:
	~ITasklet() { }
	virtual long get_tasklet_id() const = 0;
	virtual std::string execute() = 0;
};