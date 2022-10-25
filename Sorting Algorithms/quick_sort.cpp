#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>

template <typename typ>
bool comp(const typ &a, const typ &b)
{
    if (a > b)
        return true;
    return false;
}

template <typename RandomIt>
RandomIt Partition(RandomIt first, RandomIt last)
{
    auto pivot = std::prev(last, 1);
    auto i = first;
    for (auto j = first; j != pivot; ++j)
    {
        // bool format
        if (*j < *pivot)
        {
            std::swap(*i++, *j);
        }
    }
    std::swap(*i, *pivot);
    return i;
}

template <typename RandomIt>
void quick_sort(RandomIt first, RandomIt last)
{
    if (std::distance(first, last) > 1)
    {
        RandomIt bound = Partition(first, last);
        quick_sort(first, bound);
        quick_sort(bound + 1, last);
    }
}

template <typename RandomIt, typename Compare>
RandomIt Partition(RandomIt first, RandomIt last, Compare compare)
{
    auto pivot = std::prev(last, 1);
    auto i = first;
    for (auto j = first; j != pivot; ++j)
    {
        // bool format
        if (compare(*j, *pivot))
        {
            std::swap(*i++, *j);
        }
    }
    std::swap(*i, *pivot);
    return i;
}

template <typename RandomIt, typename Compare>
void quick_sort(RandomIt first, RandomIt last, Compare compare)
{
    if (std::distance(first, last) > 1)
    {
        RandomIt bound = Partition(first, last, compare);
        quick_sort(first, bound, compare);
        quick_sort(bound + 1, last, compare);
    }
}

int main()
{

    // araray of integers
    int a[] = {25, 262, 534, 396, 385, 237, 2, 63, 12};
    quick_sort(std::begin(a), std::end(a));
    std::cout << std::is_sorted(std::begin(a), std::end(a)) << std::endl;

    // //vector of floats
    std::vector<float> b = {256.333, 26.53, 267.2, 1267.73, 126.732, 173.723, 732.723, 732.125, 111, 10.5};
    quick_sort(b.begin(), b.end());
    std::cout << std::is_sorted(b.begin(), b.end()) << std::endl;

    // vector of floats with compare
    quick_sort(b.begin(), b.end(), comp<float>);
    std::cout << std::is_sorted(b.begin(), b.end(), comp<float>) << std::endl;

    // vector of std::string
    std::vector<std::string> c = {"abc", "a", "polska", "andrzej", "ratata", "okrag", "b"};
    quick_sort(c.begin(), c.end());
    std::cout << std::is_sorted(c.begin(), c.end()) << std::endl;

    // vector of std::string with compare
    quick_sort(c.begin(), c.end(), comp<std::string>);
    std::cout << std::is_sorted(c.begin(), c.end(), comp<std::string>) << std::endl;
}
