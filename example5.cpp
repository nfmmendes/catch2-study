#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>

long long unsigned int factorial(int input)
{
    if (input <= 1)
        return 1;

    return input * factorial(input - 1);
}

TEST_CASE("Factorial V2", "Test function")
{
    // now let's benchmark:
    BENCHMARK("Factorial 5")
    {
        return factorial(5);
    };

    BENCHMARK("Factorial 10")
    {
        return factorial(10);
    };

    BENCHMARK("Factorial 15")
    {
        return factorial(15);
    };

    BENCHMARK("Factorial 20")
    {
        return factorial(20);
    };
}