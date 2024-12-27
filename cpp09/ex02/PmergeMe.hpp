#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);

    std::vector<unsigned int> _vector;
    std::deque<unsigned int> _deque;

    void setContainers(char **argv);
    bool is_ok_arg(std::string str);

public:
    PmergeMe(char **argv);
    ~PmergeMe();

    void display_array(std::string str);

    void merge_insertion_sort_vector(std::vector<unsigned int> tmp);
    void m_sort_vec(std::vector<unsigned int> tmp, int left, int right);
    void merge_vec(int left, int mid, int right);
};
