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
* return the number of bytes writen to. If the number of bytes return
* is equal to the size IN BYTES of the vector there is likely more data to 
* get and the vector should be made bigger. 
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
    for (const auto& x : procs)
    {
        std::cout << x.first << ": " << x.second << "\n";
    }
}

int main(int argc, char** argv, char** envp)
{
    pids.resize(100);
    auto size = get_pidlist(pids);

    while (pids.size()/sizeof(int) <= size)
    {
        pids.resize(pids.size() * 2);
        size = get_pidlist(pids);
    }

    pids.resize(size / sizeof(int));

    for (auto x : pids)
    {
        std::string name = get_proc_name(x);
        if( name != "Unable to open process. Skipping...")
            procList[x] = get_proc_name(x);
    }

    print_procs(procList);

	return 0;
}



























