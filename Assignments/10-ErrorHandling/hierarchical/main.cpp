#include "except.h"
#include "config.h"
#include <iostream>


/*
You should create a config object and read the config. 
Your Config object should continue to process the file even if there 
was error in the configfile (i.e. catch BadConfig)
*BUT* you should let the user know about the error so they can go fix the config file
for next time by throwing an exception with the line numbers of the problems.

In main:
You should instantiate a Config.
You should read the config. 
You should print any bad config lines errors to the user.
Finally, you should print out the setting asked for. 

Bonus that everyone should do:
After you get it working this far, add catch statements after main for the 
actual exceptions being thrown and print out which one is caught. 

For the myConfig.txt file provided you should get the following output:

---------------------------------------------------------------------
C:\Users\...\Instructor Solutions>hierarchical.exe myConfig.txt port
Config Line: 8 Config Not Conforming!

port: 444
-------------------------------------------------------------------------
C:\Users\...Instructor Solutions>hierarchical.exe myConfig.txt fooBar
Config Line: 8 Config Not Conforming!

EXCEPTION!!
fooBar Not Found!
-------------------------------------------------------------------------
C:\Users\Instructor Solutions>hierarchical.exe myConfig.tx fooBar
EXCEPTION!!
myConfig.tx Could not open
*/


int main(int argc, char* argv[]) try {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <ConfigFile> <Setting>\n";
        exit(0);
    }
    std::string configFile = argv[1];
    std::string key = argv[2];

    //DO STUFF.

    return 0;
}
catch (const std::exception e) {
    std::cout << "EXCEPTION!!\n";
    std::cout << e.what();
    exit(-1);
}