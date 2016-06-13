#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Vector.h"
#include <vector>

TEST_CASE("Vector Test", "[VECTOR TEST]") {

    SECTION("doubles") {
        Vector<double> a;
        a.push_back(1.2);
        a.push_back(2.3);
        a.push_back(3.4);
        a.push_back(4.5);
        std::vector<double> reference{ 1.2,2.3,3.4,4.5 };
        REQUIRE(a[0] == 1.2);
        REQUIRE(a[1] == 2.3);
        REQUIRE(a[2] == 3.4);
        REQUIRE(a[3] == 4.5);
        int i = 0;
        for (auto x : a)
        {
            REQUIRE(x == reference[i]);
            i++;
        }
        REQUIRE(a.size() == reference.size());
    }

    SECTION("ints") {
        Vector<int> a;
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        std::vector<double> reference{ 1,2,3,4 };
        REQUIRE(a[0] == reference[0]);
        REQUIRE(a[1] == reference[1]);
        REQUIRE(a[2] == reference[2]);
        REQUIRE(a[3] == reference[3]);
        int i = 0;
        for (auto x : a)
        {
            REQUIRE(x == reference[i]);
            i++;
        }
        REQUIRE(a.size() == reference.size());
    }

    /*
    SECTION("initializer BONUS!") {
        Vector<int> a{ 1,2,3,4,5,6,7,8,9,10 };
        std::vector<int> r{ 1,2,3,4,5,6,7,8,9,10 };
        auto ri = r.begin();
        for (auto ai = a.begin(); ai != a.end() || ri != r.end(); ++ai, ++ri)
            REQUIRE(*ai == *ri);
        REQUIRE(a.size() == r.size());
    }
    */
}