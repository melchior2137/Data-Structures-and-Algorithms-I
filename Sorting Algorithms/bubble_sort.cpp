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

template <typename BubbleIterator>
void bubble_sort(BubbleIterator begin, BubbleIterator end)
{
    BubbleIterator i;
    BubbleIterator j;

    for (i = begin; i != end; ++i)
        for (j = begin; j < i; ++j)
            if (*i < *j)
                std::swap(*i, *j);
}

template <typename BubbleIterator, typename Compare>
void bubble_sort(BubbleIterator begin, BubbleIterator end, Compare comp)
{
    BubbleIterator i;
    BubbleIterator j;

    for (i = begin; i != end; ++i)
        for (j = begin; j < i; ++j)
            if (comp(*i, *j))
                std::swap(*i, *j);
}

int main()
{

    //araray of integers
    int a[] = {25, 262, 534, 396, 385, 237, 2, 63, 12};
    bubble_sort(std::begin(a), std::end(a));
    std::cout << std::is_sorted(std::begin(a), std::end(a))<<std::endl;

    //vector of floats
    std::vector<float> b = {256.333, 26.53, 267.2, 1267.73, 126.732, 173.723, 732.723, 732.125, 111, 10.5};
    bubble_sort(b.begin(), b.end());
    std::cout << std::is_sorted(b.begin(), b.end())<<std::endl;

    //vector of floats with compare
    bubble_sort(b.begin(), b.end(), comp<float>);
    std::cout << std::is_sorted(b.begin(), b.end(), comp<float>)<<std::endl;

    //vector of std::string
    std::vector<std::string> c = {"abc", "a", "polska", "andrzej", "ratata", "okrag", "b"};
    bubble_sort(c.begin(), c.end());
    std::cout << std::is_sorted(c.begin(), c.end())<<std::endl;

    //vector of std::string with compare
    bubble_sort(c.begin(), c.end(), comp<std::string>);
    std::cout << std::is_sorted(c.begin(), c.end(), comp<std::string>)<<std::endl;
}
