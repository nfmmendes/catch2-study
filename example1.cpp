#include <catch2/catch_test_macros.hpp>

TEST_CASE("Test with variables", "[starting]")
{
    auto a = 2;
    auto b = 4;

    REQUIRE(a + b == 6);
    REQUIRE(a + b == b + a);
    REQUIRE(a * b == 8);
    REQUIRE(b * a == a * b);
    REQUIRE(a - b == -2);
    REQUIRE(b - a == 2);
    REQUIRE_FALSE(a - b == b - a);
    REQUIRE(a / b == 0);
    REQUIRE(b / a == 2);
    REQUIRE_FALSE(a / b == b / a);
    REQUIRE(a * 1.0 / b == 0.5);
}