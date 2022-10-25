#include <iostream>     //std::cout
#include <iterator>     //std::iterator, std::prev, std::distance
#include <algorithm>    //std::shuffle, std::swap, std::is_sorted
#include <vector>       // std::vector
#include <string>       // std::string
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock


//custom compare function
template <typename typ>
bool comp(const typ &a, const typ &b)
{
    if (a > b)
        return true;
    return false;
}

//bubble sort without custom compare function
template <typename BubbleIterator>
void bubble_sort(BubbleIterator begin, BubbleIterator end)
{
    for (BubbleIterator i = begin; i != std::prev(end); ++i)
        for (BubbleIterator j = begin; j < std::prev(end); ++j)
            if (*j > *(std::next(j)))
                std::swap(*j, *(std::next(j)));
}

//bubble sort with custom compare function
template <typename BubbleIterator, typename Compare>
void bubble_sort(BubbleIterator begin, BubbleIterator end, Compare comp)
{
    for (BubbleIterator i = begin; i != std::prev(end); ++i)
        for (BubbleIterator j = begin; j < std::prev(end); ++j)
            if (comp(*(std::next(j)), *j))
                std::swap(*j, *(std::next(j)));
}

int main()
{
    unsigned seed; //seed for shuffling arrays and vectors

    //araray of integers
    int a[] = {25, 262, 534, 396, 385, 237, 2, 63, 12};
    bubble_sort(std::begin(a), std::end(a));
    std::cout << std::is_sorted(std::begin(a), std::end(a))<<std::endl;

    //vector of floats
    std::vector<float> b = {256.333, 26.53, 267.2, 1267.73, 126.732, 173.723, 732.723, 732.125, 111, 10.5};
    bubble_sort(b.begin(), b.end());
    std::cout << std::is_sorted(b.begin(), b.end())<<std::endl;

    //vector of floats with compare
    seed = std::chrono::system_clock::now().time_since_epoch().count(); //random seed
    std::shuffle(b.begin(), b.end(), std::default_random_engine(seed)); //shuffle vector
    bubble_sort(b.begin(), b.end(), comp<float>);
    std::cout << std::is_sorted(b.begin(), b.end(), comp<float>)<<std::endl;

    //vector of std::string
    std::vector<std::string> c = {"abc", "a", "polska", "andrzej", "ratata", "okrag", "b"};
    bubble_sort(c.begin(), c.end());
    std::cout << std::is_sorted(c.begin(), c.end())<<std::endl;

    //vector of std::string with compare
    seed = std::chrono::system_clock::now().time_since_epoch().count(); //random seed
    std::shuffle(c.begin(), c.end(), std::default_random_engine(seed)); //shuffle vector
    bubble_sort(c.begin(), c.end(), comp<std::string>);
    std::cout << std::is_sorted(c.begin(), c.end(), comp<std::string>)<<std::endl;
}
