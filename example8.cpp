#include <catch2/catch_test_macros.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <catch2/generators/catch_generators_range.hpp>
#include <utility>
#include <map>
using std::make_pair;
using std::map;
using std::pair;

long long unsigned int
factorial(unsigned int input)
{
    if (input <= 1)
        return 1;

    return input * factorial(input - 1);
}

// This function works only if (total - part) <= 20
long long unsigned int combination(int total, int part)
{
    if (part > total)
        return 0;

    long long unsigned int diffFactorial = factorial(total - part);

    long long unsigned int product = 1;
    for (int i = part + 1; i <= total; i++)
    {
        product *= i;
        if (diffFactorial % 2 == 0 && product % 2 == 0)
        {
            product /= 2;
            diffFactorial /= 2;
        }

        if (diffFactorial % 3 == 0 && product % 3 == 0)
        {
            product /= 3;
            diffFactorial /= 3;
        }

        if (diffFactorial % 5 == 0 && product % 5 == 0)
        {
            product /= 5;
            diffFactorial /= 5;
        }
    }

    return product / diffFactorial;
}

long long unsigned int pascalTriangleCombination(int total, int part)
{
    if (part > total)
        return 0;
    if (total <= 1 && part <= 1)
        return 1;
    if (total == part || part == 0)
        return 1;

    int a = pascalTriangleCombination(total - 1, part);
    int b = pascalTriangleCombination(total - 1, part - 1);

    return a + b;
}

std::map<pair<int, int>, long long unsigned int> results{
    {pair<int, int>(20, 5), 15504},
    {pair<int, int>(20, 10), 184756},
    {pair<int, int>(20, 15), 15504},
    {pair<int, int>(25, 5), 53130},
    {pair<int, int>(25, 10), 3268760},
    {pair<int, int>(25, 15), 3268760},
    {pair<int, int>(30, 5), 142506},
    {pair<int, int>(30, 10), 30045015},
    {pair<int, int>(30, 15), 155117520},
};

TEST_CASE("Test combinations")
{
    int total = GENERATE(20, 25);

    SECTION("Part on combination")
    {
        int part = GENERATE(5, 10, 15);

        REQUIRE(combination(total, part) == results[make_pair(total, part)]);
    }
}

TEST_CASE("Combination fails")
{
    int total = 30;
    int part = 5;
    REQUIRE(combination(total, part) != results[make_pair(total, part)]);
}

TEST_CASE("Test pascal triangle combinations")
{
    int total = GENERATE(20, 25, 30);

    SECTION("Part on combination")
    {
        int part = GENERATE(5, 10, 15);

        REQUIRE(pascalTriangleCombination(total, part) == results[make_pair(total, part)]);
    }
}