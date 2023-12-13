#include <catch2/catch_test_macros.hpp>
#include <climits>

long long unsigned int factorial(unsigned int input)
{
    if (input <= 1)
        return 1;

    return input * factorial(input - 1);
}

TEST_CASE("Factorial", "Test function")
{
    REQUIRE(factorial(0) == 1);
    REQUIRE(factorial(1) == 1);
    REQUIRE(factorial(2) == 2);
    REQUIRE(factorial(3) == 6);
    REQUIRE(factorial(6) == 6 * factorial(5));
    REQUIRE(factorial(20) < ULLONG_MAX);
}

TEST_CASE("Factorial overflow", "Test function")
{
    REQUIRE(factorial(20) / 20 == factorial(19));
    REQUIRE(factorial(21) < ULLONG_MAX);
    REQUIRE_FALSE(factorial(21) / 21 == factorial(20));
}