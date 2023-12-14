#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark_all.hpp>
#include <vector>
#include <string>
using std::string;
using std::swap;
using std::vector;

template <class T>
void bubbleSort(vector<T> &values)
{
    for (int i = 0; i < values.size() - 1; i++)
    {
        for (auto j = i + 1; j < values.size(); j++)
        {
            if (values[j] < values[i])
                swap(values[j], values[i]);
        }
    }
}

template <class T>
void insertionSort(vector<T> &values)
{
    for (auto i = 0; i < values.size() - 1; i++)
    {
        int lowerIndex = 0;
        for (auto j = i + 1; j < values.size(); j++)
        {
            if (values[j] < values[lowerIndex])
                lowerIndex = j;
        }

        swap(values[i], values[lowerIndex]);
    }
}

TEST_CASE("Ordering single int", "[Ordering vector int]")
{
    vector<int> oneElementInput(1, 5);
    REQUIRE(oneElementInput.size() == 1);

    BENCHMARK("Bubble sort")
    {
        return bubbleSort(oneElementInput);
    };

    BENCHMARK("Insertion sort")
    {
        return insertionSort(oneElementInput);
    };
}

TEST_CASE("Ordering two ints", "[Ordering vector int]")
{
    BENCHMARK("Bubble sort")
    {
        vector<int> twoElementsInput = {7, 5};
        return bubbleSort(twoElementsInput);
    };

    BENCHMARK("Insertion sort")
    {
        vector<int> twoElementsInput = {7, 5};
        return insertionSort(twoElementsInput);
    };
}

TEST_CASE("Ordering ten ints", "[Ordering vector int]")
{
    BENCHMARK("Bubble sort")
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        return bubbleSort(tenElementsInput);
    };

    BENCHMARK("Insertion sort")
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        return insertionSort(tenElementsInput);
    };
}

TEST_CASE("Ordering ten ints advanced", "[Ordering vector int]")
{
    BENCHMARK("Bubble sort")
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        return bubbleSort(tenElementsInput);
    };

    BENCHMARK_ADVANCED("Bubble sort advanced")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        meter.measure([&]()
                      { return bubbleSort(tenElementsInput); });
    };

    BENCHMARK("Insertion sort")
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        return insertionSort(tenElementsInput);
    };

    BENCHMARK_ADVANCED("Insertion sort advanced")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<int> tenElementsInput = {7, 5, 2, 3, 1, 4, 8, 6, 9, 0};
        meter.measure([&]()
                      { return insertionSort(tenElementsInput); });
    };
}

TEST_CASE("Ordering single string", "[Ordering vector string]")
{
    vector<string> oneElementInput{"first"};
    REQUIRE(oneElementInput.size() == 1);

    BENCHMARK("Bubble sort")
    {
        return bubbleSort(oneElementInput);
    };

    BENCHMARK("Insertion sort")
    {
        return insertionSort(oneElementInput);
    };
}

TEST_CASE("Ordering two strings", "[Ordering vector string]")
{
    BENCHMARK("Bubble sort")
    {
        vector<string> twoElementsInput{"end", "begin"};
        return bubbleSort(twoElementsInput);
    };

    BENCHMARK("Insertion sort")
    {
        vector<int> twoElementsInput{"end", "begin"};
        return insertionSort(twoElementsInput);
    };
}

TEST_CASE("Ordering ten strings", "[Ordering vector string]")
{
    BENCHMARK("Bubble sort")
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth"};
        return bubbleSort(tenElementsInput);
    };

    BENCHMARK("Insertion sort")
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth"};
        return insertionSort(tenElementsInput);
    };
}

TEST_CASE("Ordering ten strings advanced", "[Ordering vector strings]")
{
    BENCHMARK("Bubble sort")
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth"};
        return bubbleSort(tenElementsInput);
    };

    BENCHMARK_ADVANCED("Bubble sort advanced")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth"};
        meter.measure([&]()
                      { return bubbleSort(tenElementsInput); });
    };

    BENCHMARK("Insertion sort")
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "nineth", "tenth"};
        return insertionSort(tenElementsInput);
    };

    BENCHMARK_ADVANCED("Insertion sort advanced")
    (Catch::Benchmark::Chronometer meter)
    {
        vector<string> tenElementsInput{"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eigth", "nineth", "tenth"};
        meter.measure([&]()
                      { return insertionSort(tenElementsInput); });
    };
}