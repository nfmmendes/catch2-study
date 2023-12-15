#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <vector>
#include <string>
using std::string;
using std::swap;
using std::vector;

long long unsigned int factorial(unsigned int input)
{
    if (input <= 1)
        return 1;

    return input * factorial(input - 1);
}

TEST_CASE("Test generators with factorial")
{
    int i = GENERATE(1, 5, 10, 15, 20);

    REQUIRE(factorial(i) == i * factorial(i - 1));
}

TEST_CASE("Test generator range with factorial")
{
    int i = GENERATE(range(1, 5));

    REQUIRE(factorial(i) == i * factorial(i - 1));
}

TEST_CASE("Test generator filter with factorial")
{
    int i = GENERATE(filter([](int i)
                            { return i % 2 == 0; },
                            range(1, 10)));

    REQUIRE(factorial(i) == i * factorial(i - 1));
}
