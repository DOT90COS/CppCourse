#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "yourCode.h"
#include "Person.h"
#include <vector>
#include <sstream>

std::vector<Person> buildPeople()
{
    std::vector<Person> people;
    people.push_back(Person("Jeff", "Scaparra", 32));
    people.push_back(Person("Aaron", "Bray", 28));
    people.push_back(Person("Chet", "Wall", 35));
    people.push_back(Person("Charles", "Heaton", 30));
    people.push_back(Person("Agent", "Smith", 007));
    people.push_back(Person("Cleaning", "Lady", 23));
    people.push_back(Person("Mail", "Mann", 57));
    return people;
}

TEST_CASE("Test2", "[Test2]") {

    SECTION("AGE") {
        auto people = buildPeople();
        auto sortPeople = people;
        sortByAge(sortPeople);
        REQUIRE(people.size() == sortPeople.size());
        REQUIRE(sortPeople.front().age() == 7);
        REQUIRE(sortPeople.back().age() == 57);
        REQUIRE(sortPeople[4].getLast() == "Scaparra");
    }

    SECTION("Name") {
        auto people = buildPeople();
        auto sortPeople = people;
        sortByLastName(sortPeople);
        REQUIRE(people.size() == sortPeople.size());
        REQUIRE(sortPeople.front().getLast() == "Bray");
        REQUIRE(sortPeople.back().getLast() == "Wall");
        REQUIRE(sortPeople[4].getLast() == "Scaparra");
    }

    SECTION("Printing") {
        std::stringstream ss;
        auto people = buildPeople();
        ss << people[0];
        REQUIRE(ss.str() == "Jeff Scaparra, Age: 32");
        ss.str("");
        ss << people[1];
        REQUIRE(ss.str() == "Aaron Bray, Age: 28");
        ss.str("");
        ss << people.back();
        REQUIRE(ss.str() == "Mail Mann, Age: 57");
    }

}