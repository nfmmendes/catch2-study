#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include <catch2/generators/catch_generators.hpp>
#include <catch2/generators/catch_generators_all.hpp>
#include <utility>
#include <map>
using std::make_pair;
using std::map;
using std::pair;
using ullong = long long unsigned int;
using cacheMap = map<pair<int, int>, ullong>;

ullong pascalTriangleCombination(int total, int part)
{
    if (total < part)
        return 0;
    if (total <= 1 && part <= 1)
        return 1;
    if (total == part || part == 0)
        return 1;

    int a = pascalTriangleCombination(total - 1, part);
    int b = pascalTriangleCombination(total - 1, part - 1);

    return a + b;
}

ullong improvedPascalTriangleCombination(int total, int part, cacheMap &cache)
{
    if (total < part)
        return 0;
    if (total < 0 || part < 0)
        return 0;
    if (total <= 1 && part <= 1)
        return 1;
    if (total == part || part == 0)
        return 1;

    auto key = make_pair(total, part);
    if (cache.contains(key))
        return cache[key];

    int a = improvedPascalTriangleCombination(total - 1, part, cache);
    int b = improvedPascalTriangleCombination(total - 1, part - 1, cache);

    cache[key] = a + b;

    return a + b;
}

ullong improvedPascalTriangleCombination(int total, int part)
{
    cacheMap cache;
    return improvedPascalTriangleCombination(total, part, cache);
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

TEST_CASE("Test pascal triangle combinations")
{
    int total = GENERATE(20, 25, 30);

    SECTION("Part on combination")
    {
        int part = GENERATE(5, 10, 15);

        REQUIRE(pascalTriangleCombination(total, part) == results[make_pair(total, part)]);
    }
}

TEST_CASE("Test improved pascal triangle combinations")
{
    int total = GENERATE(20, 25, 30);

    SECTION("Part on combination")
    {
        int part = GENERATE(5, 10, 15);

        REQUIRE(improvedPascalTriangleCombination(total, part) == results[make_pair(total, part)]);
    }
}

TEST_CASE("Combination functions benchmarking")
{
    auto total = GENERATE(20, 25, 30);

    SECTION("Benchmarks")
    {
        auto part = GENERATE(5, 10, 15, 25);
        WHEN("Total is greater than part")

        if (total < part)
            SKIP(total);

        BENCHMARK_ADVANCED("Normal")
        (Catch::Benchmark::Chronometer meter)
        {
            meter.measure([=]()
                          { return pascalTriangleCombination(total, part); });
        };

        BENCHMARK_ADVANCED("Improved")
        (Catch::Benchmark::Chronometer meter)
        {
            meter.measure([=]()
                          { return improvedPascalTriangleCombination(total, part); });
        };
    }
}