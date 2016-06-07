#include <iostream>
#include <fstream>
//Add container headers that you want to use here
#include <map>
#include <set>
#include <vector>
////////////////////////////////////////////////

/**************************************************
Write an application that will:

* Take exactly one command line parameter with the filename of
  the file to be processed

* Read the numbers in from that file. The file should be in the 
  format of "98, 43, 34". i.e. it will start with and number and 
  end with a number. All numbers will be seperated by a comma. 

* Determine the min number, the max number, the median number and
  the mean number and print them to the screen. 

* Determine the number that appears the most in the file.

* Write all the numbers back out to a file named the same as the input
  filename BUT with .sorted.txt appended to the filename. 

  YOU ARE NOT ALLOWED TO USE AN ARRAY TO STORE DATA ONLY STL CONTAINERS!!!: 

Things to think about:
* Which containers would be good for sorting the data?
* Which containers would be good for indexing the numbers?
* What container would make it easy to get the median number out of? 

***************************************************/



std::multiset<int> readInData(const std::string& filename)
{
    std::ifstream inFile(filename);
    std::multiset<int> data;

    int tmp{ 0 };
    inFile >> tmp;
    data.insert(tmp);
    while (inFile && !inFile.eof())
    {
        char tmpChar{ 0 };
        inFile >> tmpChar >> tmp;
        data.insert(tmp);
    }
    return data;
}

std::set<int> mode(const std::multiset<int>& data)
{
    std::set<int> modes;
    int maxCount = 1;
    for (auto x : data)
    {
        auto count = data.count(x);
        if (count > maxCount)
        {
            modes.clear();
            maxCount = data.count(x);
            modes.insert(x);
        }
        else if (count == maxCount)
        {
            modes.insert(x);
        }
    }
    return modes;
}

double median(const std::multiset<int>& data)
{
    if (data.empty())
        return 0;

    const auto n = data.size();
    auto itr = data.cbegin();
    std::advance(itr, n / 2);

    //Middle or average of two middle values
    if (n % 2 == 0) //even number of elements
    {
        const auto itr2 = itr--;
        return (*itr + *itr2) / 2.0;
    }
    return *itr;
}

void printStats(const std::multiset<int>& data)
{
    if (data.size() > 1)
    {
        std::cout << "Min: " << *data.begin() << "\n";
        std::cout << "Max: " << *data.rbegin() << "\n";
        long long total = 0;
        for (auto x : data)
            total += x;
        std::cout << "Avg: " << total / data.size() << "\n";
        std::cout << "Median: " << median(data) << "\n";
        auto modes = mode(data);
        std::cout << "Mode(s): ";
        auto count = data.count(*modes.begin());
        for (auto x : modes)
            std::cout << x << "  ";
        std::cout << " showed up " << count << " times!\n ";
    }
    else
    {
        std::cout << "Empty Data Set!!!\n";
    }
}

void writeFile(const std::string& filename, const std::multiset<int>& data)
{
    std::string writeFile = filename + ".sorted.txt";
    std::ofstream outFile(writeFile);
    if (!outFile)
    {
        std::cerr << "Bad output file!\n";
        return;
    }
    bool first = true;
    for (auto x : data)
    {
        if (outFile)
        {
            if (first) outFile << x;
            else outFile << ", " << x;
        }
        first = false;
    }
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << "USAGE: " << argv[1] << " <FILENAME>\n";
        return 0;
    }

    std::string filename = argv[1];
    auto data = readInData(filename);
    printStats(data);
    writeFile(filename, data);
}












