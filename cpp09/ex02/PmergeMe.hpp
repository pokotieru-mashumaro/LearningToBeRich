#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
private:
    PmergeMe();
    PmergeMe(const PmergeMe &copy);
    PmergeMe &operator=(const PmergeMe &copy);

    std::vector<int> _vector;
	std::vector<int> _jacob;

    std::deque<int> _deque;
    std::vector<int> _jacob_deq;

    bool is_ok_arg(std::string str);
    int jacobsthal(int n);

    void setContainers_vec(char **argv);
    void setContainers_deq(char **argv);
    void setJacob();
    void setJacob_deq();

    void rearrange_vec(std::vector<int>& vec, std::vector<int>& indexes);
    void rearrange_deq(std::deque<int>& vec, std::deque<int>& indexes);

public:
    PmergeMe(char **argv);
    ~PmergeMe();

    void display_array(std::string str);


    void set_mainchain_pend(std::vector<int>& vec, std::vector<int>& mainchain, std::vector<int>& pend);
    void set_mainchain_pen_deq(std::deque<int>& vec, std::deque<int>& mainchain, std::deque<int>& pend);

    void sort_vec();
    void sort_deq();

    void merge_insertion_sort(std::vector<int>& vec, std::vector<int>& indexes);
    void merge_insertion_sort_deq(std::deque<int>& vec, std::deque<int>& indexes);
    void binaryInsert(std::vector<int>& mainchain, std::vector<int>& pend, std::vector<int>& i_main, std::vector<int>& i_pend);
    void binaryInsert_deq(std::deque<int>& mainchain, std::deque<int>& pend, std::deque<int>& i_main, std::deque<int>& i_pend);
};
