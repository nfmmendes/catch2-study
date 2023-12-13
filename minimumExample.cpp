#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test obvious", "[starting]")
{
    REQUIRE(2 + 2 == 4);
    REQUIRE(2 * 4 == 8);
    REQUIRE(4 / 2 == 2);
    REQUIRE(4 - 1 == 3);
}
