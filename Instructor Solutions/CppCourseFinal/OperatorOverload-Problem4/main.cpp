#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "ScaledNum.h"

TEST_CASE("ScaledNums", "[ScaledNums]") {

    SECTION("operator==") {
        ScaledNum num1(4.0, 1.0);
        ScaledNum num2(2.0, 2.0);
        ScaledNum num3(8.0, 0.5);

        REQUIRE(num1 == num2);
        REQUIRE(num2 == num3);
        REQUIRE(num1 == num3);
    }

    SECTION("operator!=") {
        ScaledNum num1(4.0, 3.0);
        ScaledNum num2(2.0, 2.0);
        ScaledNum num3(8.1, 1.5);

        REQUIRE(num1 != num2);
        REQUIRE(num2 != num3);
        REQUIRE(num1 != num3);
    }

    SECTION("Add") {
        ScaledNum num1(2.0, 2.0);
        ScaledNum num2(2.0, 3.0);
        auto num3 = num1 + num2;
        num1 += num2;
        REQUIRE(num1 == num3);
        REQUIRE(num1 == ScaledNum(10, 1));
    }

    SECTION("Sub") {
        ScaledNum num1(2.0, 2.0);
        ScaledNum num2(2.0, 3.0);
        auto num3 = num2 - num1;
        num2 -= num1;
        REQUIRE(num3 == num2);
        REQUIRE(num2 == ScaledNum(2, 1));
    }

    SECTION("MUL") {
        ScaledNum num1(2.0, 5.0);
        ScaledNum num2(10.0, 1.0);
        auto num3 = num1*num2;
        num1 *= num2;
        REQUIRE(num1 == num3);
        REQUIRE(num1 == ScaledNum(100, 1));
    }

    SECTION("Div") {
        ScaledNum num1(100.0, 1);
        ScaledNum num2(1.0, 0.5);
        auto num3 = num1 / num2;
        num1 /= num2;
        REQUIRE(num1 == num3);
        REQUIRE(num1 == ScaledNum(200.0, 1.0));
    }

}