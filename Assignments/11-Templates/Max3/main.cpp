#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "max.h"
#include <vector>
#include <deque>
#include <list>
#include <set>

TEST_CASE("Max Test", "[Max Test]") {
    SECTION("Max Vector Ints") {
        std::vector<int> nums{ 1,3,2,4,5,7,6,8,9,10 };
        Max<decltype(nums)> max(nums);
        REQUIRE(max.getMin() == 1);
        REQUIRE(max.getMax() == 10);
        REQUIRE(max.getMean() == 5.5);
        typename decltype(nums) sorted = max.getSorted();
        for(auto i = 0U; i < 10; ++i)
            REQUIRE(sorted[i] == (i + 1));
    }
    SECTION("Max Vector Doubles") {
        std::vector<double> nums{ 1.0,3.0,2.0,4.0,5.0,7.0,6.0,8.0,9.0,10.0 };
        Max<decltype(nums)> max(nums);
        REQUIRE(max.getMin() == 1.0);
        REQUIRE(max.getMax() == 10.0);
        REQUIRE(max.getMean() == 5.5);
        auto sorted = max.getSorted();
        for(auto i = 0U; i < 10; ++i)
            REQUIRE(sorted[i] == (i + 1));
    }
    SECTION("Max Deque Ints") {
        std::deque<int> nums{ 1,3,2,4,5,7,6,8,9,10 };
        Max<decltype(nums)> max(nums);
        REQUIRE(max.getMin() == 1);
        REQUIRE(max.getMax() == 10);
        REQUIRE(max.getMean() == 5.5);
        typename decltype(nums) sorted = max.getSorted();
        for(auto i = 0U; i < 10; ++i)
            REQUIRE(sorted[i] == (i + 1));
    }
    SECTION("Max Set Ints") {
        std::set<int> nums{ 1,3,2,4,5,7,6,8,9,10 };
        Max<decltype(nums)> max(nums);
        REQUIRE(max.getMin() == 1);
        REQUIRE(max.getMax() == 10);
        REQUIRE(max.getMean() == 5.5);
        typename decltype(nums) sorted = max.getSorted();
        for(auto i = 0U; i < 10; ++i)
            REQUIRE(sorted[i] == (i + 1));
    }
    SECTION("Max List Ints") {
        std::list<int> nums{ 1,3,2,4,5,7,6,8,9,10 };
        Max<decltype(nums)> max(nums);
        REQUIRE(max.getMin() == 1);
        REQUIRE(max.getMax() == 10);
        REQUIRE(max.getMean() == 5.5);
        typename decltype(nums) sorted = max.getSorted();
        for(auto i = 0U; i < 10; ++i)
            REQUIRE(sorted[i] == (i + 1));
    }
}
