#define CATCH_CONFIG_MAIN
#include <cstdint>
#include "catch.hpp"
#include "Header.h"
#include <vector>
#include <deque>
#include <list>
#include <set>

template<typename T> 
void checkAccumulate(T thing) {
    auto count = 3;
    for (auto i = 0; i < 10; ++i, ++count)
        REQUIRE(*(thing++) == count);
}

TEST_CASE("Test3", "[Test3]") {
    SECTION("SizeOfAll") {
        std::vector<uint32_t> int100(100, 0);
        auto size = sizeOfAll(int100);
        REQUIRE(size == 400);
        std::vector<std::vector<uint64_t>> vecvec(20, std::vector<uint64_t>(10, 7));
        size = sizeOfAll(vecvec);
        REQUIRE(size == 20 * sizeof(vecvec[0]));
    }

    SECTION("Accumulate1") {
        std::vector<int> nums{ 1,2,3,4,5,6,7,8,9,10 };
        std::deque<int> nums2(nums.begin(), nums.end());
        std::list<int> nums3(nums.begin(), nums.end());
        //std::set<int> nums4(nums.begin(), nums.end());
        accumulate(nums.begin(), nums.end(), 2);
        accumulate(nums2.begin(), nums2.end(), 2);
        accumulate(nums3.begin(), nums3.end(), 2);
        //accumulate(nums4.begin(), nums4.end(), 2);
        checkAccumulate(nums.begin());
        checkAccumulate(nums2.begin());
        checkAccumulate(nums3.begin());
        //checkAccumulate(nums4.begin());
    }

    SECTION("Accumulate2") {
        int nums[] = { 1,2,3,4,5,6,7,8,9,10 };
        double nums2[] = { 1,2,3,4,5,6,7,8,9,10 };
        accumulate(nums, nums + 10, 2);
        accumulate(nums2, nums2 + 10, 2.0);
        checkAccumulate((int*)nums);
        checkAccumulate((double*)nums2);
    }
}