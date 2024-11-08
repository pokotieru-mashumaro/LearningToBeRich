#ifndef   whatever_HPP
#define   whatever_HPP

#include <iostream>

template <typename T>
void swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

template <typename T>
T min(T& x, T& y)
{
    return (x > y) ? y : x;
}

template <typename T>
T max(T& x, T& y)
{
    return (x > y) ? x : y;
}

#endif
