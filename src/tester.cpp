#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>
#include "date.h"
using namespace std;

TEST_CASE("one argument constructor") {
    REQUIRE(Date(2018).str() == "Jan 1, 2018");
}

TEST_CASE("two arguments constructor") {
    REQUIRE(Date(2018, 7).str() == "Jul 1, 2018");
}

TEST_CASE("+ operator") {
    Date dd(2018, 9, 10);
    Date d = dd;

    d = dd; REQUIRE((d + 23).str() == "Oct 3, 2018");
    d = dd; REQUIRE((d + 38).str() == "Oct 18, 2018");
    d = dd; REQUIRE((d + 56).str() == "Nov 5, 2018");
    d = dd; REQUIRE((d + 91).str() == "Dec 10, 2018");
    d = dd; REQUIRE((d + 134).str() == "Jan 22, 2019");
}

TEST_CASE("Adding months") {
    Date dd(2018, 9, 10);
    Date d = dd;

    d = dd; REQUIRE(d.addMonths(7).str() == "Apr 10, 2019");
    d = dd; REQUIRE(d.addMonths(17).str() == "Feb 10, 2020");
}

TEST_CASE("<< operator") {
    Date dd(2018, 9, 10);
    stringstream sout;
    sout << dd;

    REQUIRE(sout.str() == "Sep 10, 2018");
}

TEST_CASE("str() function") {
    Date dd(2018, 9, 10);
    REQUIRE(dd.str() == "Sep 10, 2018");
}

TEST_CASE("fiveHolidays() function") {
    REQUIRE(Date::fiveHolidays().size() == 5);
}