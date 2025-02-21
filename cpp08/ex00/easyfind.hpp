#ifndef   easyfind_HPP
#define   easyfind_HPP

#include <iostream>
#include <algorithm>

template <typename T>
void easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it != container.end()) {
        std::cout << "Value found: " << value << std::endl;
    } else {
        throw std::exception();
    }
}

#endif