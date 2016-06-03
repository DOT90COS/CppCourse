#include <vector>
#include <map>
#include <deque>
#include <fstream>
#include <string>
#include <cstdint>
#include <iostream>
#include "defs.hpp"
/**
* Using the following functions (defined in defs.hpp):
* 
* std::string get_proc_name(uint32_t pid);
* uint32_t get_pidlist(std::vector<uint32_t>& buf);
*
* 1.) Call get_pidlist, providing a vector as input. It will
* return the number of bytes written in the vector. If the number
* of bytes is equal to the number of BYTES in the vector then there
* is likely more data and the vector should be made bigger. 
* 
* 2.) Resize the vector to accomodate the remaining PIDs
*
* 3.) Populate the procList map with all process ID/process name combinations,
* calling get_proc_name on each pid to try and retrieve its name. Make sure you
* filter out processes you aren't able to open (the string "Unable to open process. Skipping..."
* will be returned).
*
* 4.) Iterate through the map, printing the consolidated list of all processes retrieved.
*/
std::map<uint32_t, std::string> procList;
std::vector<uint32_t> pids;

void print_procs(const std::map<uint32_t, std::string>& procs)
{

}

int main(int argc, char** argv, char** envp)
{
	
	return 0;
}
