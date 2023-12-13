#include <catch2/catch_test_macros.hpp>
#include <string>
using std::string;

string value = "simple";

TEST_CASE("Testing value")
{
    REQUIRE(value == "simple");
}

TEST_CASE("Hidding string")
{
    string value = "complex";

    REQUIRE(value == "complex");
}

TEST_CASE("Testing section sharing", "[Section isolation]")
{
    // This variable is created again before each section.
    string value = "complex";

    SECTION("Test then change then test")
    {
        REQUIRE(value == "complex");
        value = "simple";
        REQUIRE(value == "simple");
    }

    SECTION("Test again")
    {
        REQUIRE(value == "complex");
    }
}