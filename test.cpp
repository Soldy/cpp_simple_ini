#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "subs/trim/just_trim.hpp"
#include "simple_ini.hpp"


std::map<std::string, std::string> ini;
TEST_CASE("simple test") {
    SUBCASE("preparation") {
        ini = simple_ini_tool::read("example.ini");
    };
    SUBCASE("integer") {
        CHECK(ini["test_number"] == "1");
    };
    SUBCASE("string") {
        CHECK(ini["test_string"] == "some test string");
    };
};
