#include <vector>
#include <iostream>
#include <type_traits>
#include <iterator>


template<typename itr>
typename itr::value_type mean(itr first, itr last) {
    typename itr::value_type tmp = 0;
    for(auto it = first; it != last; ++it)
        tmp += *it;
    return tmp / (std::distance(first, last));
}


template<typename T>
T mean(T* first, T* last){
    T tmp = 0;
    for (auto ptr = first; ptr < last; ++ptr)
        tmp += *ptr;
    return tmp / (last - first);
}

int main()
{
    std::vector<int> vecNums{ 1,2,3,4,5,6,7,8,9,10 };
    int arrayNums[] = { 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int>::iterator::value_type x = 0;
    std::cout << "The mean of vecNums is " << mean(vecNums.begin(), vecNums.end()) << "\n";
    
    //int* doesn't have a member called value type. 
    std::cout << "the mean of arrayNums is " << mean(arrayNums, arrayNums + 10) << "\n"; 

}