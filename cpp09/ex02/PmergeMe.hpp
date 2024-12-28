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

    std::vector<int> _vector;
	std::vector<int> _jacobSequence;

    std::deque<int> _deque;

    void setContainers_vec(char **argv);
    void setContainers_deq(char **argv);
    bool is_ok_arg(std::string str);
    int jacobsthal(int n);

public:
    PmergeMe(char **argv);
    ~PmergeMe();

    void display_array(std::string str);

    void createVectorPairs();
    void createJacobSequence();

    void set_mainchain_pend(std::vector<int>& vec, std::vector<int>& mainchain, std::vector<int>& pend);
    void sort_vec();
    void merge_insertion_sort(std::vector<int>& vec, std::vector<int>& indexes);

};
