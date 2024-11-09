#ifndef   easyfind_HPP
#define   easyfind_HPP

#include <iostream>

template <typename T, size_t N>
void easyfind(T (&container)[N], int value) {
    for (size_t i = 0; i < N; i++) {
        if (container[i] == value) {
            std::cout << "Value found: " << value << std::endl;
            return ;
        }
    }
    throw std::exception();
}

#endif