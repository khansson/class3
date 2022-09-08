
#include <cmath>

#include <array>
#include <cassert>

#include <vector>
#include <functional>

#include <algorithm>

#include <numeric>

#include "SummingExamples.hpp"
double CppStyle()
{

    constexpr int Size = 1000;

    std::array<double, Size> TestArray;

    // Use regular Arrays
    for (int i = 0; i < Size; i++)
    {
        TestArray.at(i) = std::sqrt(2) * i;
    }

    // Have the code error, but not corrupt your system
    //  TestArray.at(2000) = 5;

    int i { 0 };
    for (auto &elem : TestArray)
    {
        elem = std::sqrt(2) * i++;
    }

    std::generate(TestArray.begin(), TestArray.end(), [n = 0]() mutable { return std::sqrt(2) * n++; });

    double sum = 0;
    for (const auto &elem : TestArray)
    {
        sum += elem;
    }

    double TempSum = std::reduce(TestArray.begin(), TestArray.end());

    assert(sum == TempSum);

    TempSum = std::reduce(TestArray.begin(), TestArray.end(), 0.0);

    assert(sum == TempSum);

    TempSum = std::reduce(TestArray.begin(), TestArray.end(), 0.0, std::plus<double>());

    assert(sum == TempSum);

    TempSum = std::reduce(TestArray.begin(), TestArray.end(), 0.0,
                          [](const auto a, const auto b) { return a + b; });

    assert(sum == TempSum);

    TempSum = std::accumulate(TestArray.begin(), TestArray.end(), 0.0);

    assert(sum == TempSum);

    return sum;
}

double CppStyle(int Size)
{

    std::vector<double> TestArray;

    TestArray.resize(Size);
    int i{0};
    for (auto &elem : TestArray)
    {
        elem = std::sqrt(2) * i++;
    }

    TestArray.clear();

    TestArray.reserve(Size);

        for (i = 0; i < Size; i++)
    {
        const auto value = i * std::sqrt(2);
        TestArray.push_back(value);
    }

    TestArray.clear();

    std::generate_n(std::back_inserter(TestArray), Size, [n = 0]() mutable { return std::sqrt(2) * n++; });

    double sum = 0;
    for (const auto &elem : TestArray)
    {
        sum += elem;
    }

    double sum2 = std::reduce(TestArray.begin(), TestArray.end());

    assert((sum == sum2) && "The sums didn't match!!");

    return sum;
}