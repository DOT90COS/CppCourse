#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "unique_ptr.h"
#include <type_traits>

TEST_CASE("Unique_ptr Test", "[Unique_ptr Test]") {
    SECTION("Unique_ptr int*") {
        unique_ptr<int> pointer(new int(42));
        REQUIRE(*pointer == 42);
        REQUIRE(std::is_copy_constructible<decltype(pointer)>::value == false);
        REQUIRE(std::is_copy_assignable<decltype(pointer)>::value == false);
    }

    SECTION("TEST DELETE") {
        bool deleted = false;
        auto intptr = new int(42);
        auto checkDelete = [&deleted, intptr](int* ptr) {
            if (intptr == ptr) {
                delete ptr;
                deleted = true;
            }
        };
        {
            unique_ptr<int> foo(intptr, checkDelete);
        }
        REQUIRE(deleted);
    }
}


