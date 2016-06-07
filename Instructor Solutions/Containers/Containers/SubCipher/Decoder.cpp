#include <iostream>
#include <fstream>
//Add container headers that you want to use here
#include "..\SubCipherEncrypt\sublib.h"
////////////////////////////////////////////////

/**************************************************
Write an application that will:
Decode a subsitution cipher encoded message

* You program should take 2 parameters
* 1st - encrypted message filename
* 2nd - the filename containing the key

It should decode the message and output to a file name
the encrypted files name appended with .clear.txt
***************************************************/
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <FILENAME> <KEY>\n";
        return 0;
    }

    std::string filename = argv[1];
    auto key = readKey(argv[2], KeyType::decrypt);
    auto data = readFile(filename);
    auto encoded = encode(data, key);
    filename += ".clear.txt";
    writeData(encoded, filename);
}