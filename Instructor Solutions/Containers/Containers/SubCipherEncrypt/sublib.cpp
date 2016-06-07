#include <iostream>
#include <fstream>
#include "sublib.h"

std::map<char, char> readKey(const std::string& filename, KeyType type)
{
    std::ifstream inFile(filename);
    char from = 'a';
    std::map<char, char> key;
    while (inFile && from <= 'z')
    {
        if (type == KeyType::encrypt) //build encrypt key
        {
            inFile >> key[from];
        }
        else  //build decrypt key
        {
            char tmp;
            inFile >> tmp;
            key[tmp] = from;
        }
        from++;
    }
    return key;
}

std::vector<std::string> encode(const std::vector<std::string>& data, std::map<char, char> key)
{
    std::vector<std::string> encode;
    for (const auto& line : data)
    {
        std::string newLine;
        for (auto c : line)
        {
            if (key.count(tolower(c)))
                newLine.push_back(key[tolower(c)]);
            else
                newLine.push_back(c);
        }
        encode.push_back(newLine);
    }
    return encode;
}

void writeData(const std::vector<std::string> data, const std::string& filename)
{
    std::ofstream outFile(filename);

    for (const auto& line : data)
    {
        if (outFile)
        {
            outFile << line << "\n";
        }
        else
        {
            std::cerr << "An error occured writing the file.";
            break;
        }
    }

}

std::vector<std::string> readFile(const std::string& filename)
{
    std::ifstream inFile(filename);
    std::string line;
    std::vector<std::string> file;
    while (std::getline(inFile, line))
    {
        file.push_back(line);
    }
    return file;
}