#include "PmergeMe.hpp"
void display_vec(std::vector<int> vec);

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(char **argv)
{
    setContainers_vec(argv);
    setJacob();
    std::cout << "jacob: ";
    std::cout << "jacob 0: " << jacobsthal(0) << std::endl;
    std::cout << "jacob 1: " << jacobsthal(1) << std::endl;
    std::cout << "jacob 2: " << jacobsthal(2) << std::endl;
    std::cout << "jacob 3: " << jacobsthal(3) << std::endl;
    std::cout << "jacob 4: " << jacobsthal(4) << std::endl;
    std::cout << std::endl;
    // display_array("before");
    sort_vec();
    // display_array("after");
}

PmergeMe::PmergeMe(const PmergeMe &copy)
{
    *this = copy;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
    if (this != &copy)
    {
        this->_vector = copy._vector;
        this->_deque = copy._deque;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

bool PmergeMe::is_ok_arg(std::string str)
{
    if (str.empty())
        return false;
    
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!isdigit(str[i]))
            return false;
    }
    
    long num = atol(str.c_str());
    if (num <= 0 || num > INT_MAX)
        return false;
        
    return true;
}

void PmergeMe::setContainers_vec(char **argv)
{
    argv++;
    while (*argv)
    {
        if (!is_ok_arg(*argv))
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        _vector.push_back(atoi(*argv));
        argv++;
    }
}

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

void PmergeMe::setJacob()
{
    int index = 2;
    size_t jcobstalIndex;

    while ((jcobstalIndex = jacobsthal(index)) < _vector.size() - 1)
    {
        _jacob.push_back(jcobstalIndex);
        index++;
    }
}

void PmergeMe::sort_vec()
{
    std::vector<int> vec = _vector;
    std::vector<int> indexes;

    merge_insertion_sort(vec, indexes);
    _vector = vec;
}

void PmergeMe::set_mainchain_pend(std::vector<int>& vec, std::vector<int>& mainchain, std::vector<int>& pend)
{
    bool is_odd = vec.size() % 2 != 0;

    for (size_t i = 0; i + 1 < vec.size(); i += 2) 
    {
        mainchain.push_back(vec[i]);
        pend.push_back(vec[i + 1]);
    }

    if (is_odd)
        pend.push_back(vec.back());
}

void rearrange_vec(std::vector<int>& vec, std::vector<int>& indexes)
{
    std::vector<int> tmp = vec;
    for (size_t i = 0; i < indexes.size(); i++)
        vec[i] = tmp[indexes[i]];
}

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, std::vector<int>& indexes)
{
    if (vec.size() <= 1)
        return ;

    std::vector<int>::iterator it_vec = vec.begin();
    std::vector<int>::iterator it_indexes = indexes.begin();
    bool indexes_empty = indexes.empty();
    for (size_t i = 0; i < vec.size() / 2; i++)
    {
        if (*it_vec < *(it_vec + 1))
        {
            std::iter_swap(it_vec, it_vec + 1);
            if (!indexes_empty)
                std::iter_swap(it_indexes, it_indexes + 1);
        }
        it_vec += 2;
        if (!indexes_empty)
            it_indexes += 2;
    }

    std::vector<int> mainchain, i_main, pend, i_pend, newIndexes;
    set_mainchain_pend(vec, mainchain, pend);
    if (!indexes_empty)
        set_mainchain_pend(indexes, i_main, i_pend);
    for (size_t i = 0; i < mainchain.size(); i++)
        newIndexes.push_back(i);
    merge_insertion_sort(mainchain, newIndexes);
    rearrange_vec(pend, newIndexes);
    if (!indexes_empty)
    {
        rearrange_vec(i_main, newIndexes);
        rearrange_vec(i_pend, newIndexes);
    }
    
    // std::cout << "before: " << std::endl;
    // display_vec(mainchain);
    // display_vec(pend);
    binaryInsert(mainchain, pend, i_main, i_pend);
	// std::cout << "after: " << std::endl;
    // display_vec(mainchain);
    // display_vec(pend);
    // std::cout << std::endl;

    vec = mainchain;
    indexes = i_main;
}

void PmergeMe::binaryInsert(std::vector<int>& mainchain, std::vector<int>& pend, std::vector<int>& i_main, std::vector<int>& i_pend)
{
    std::vector<int>::iterator	it;

    for (size_t i = 0; i < _jacob.size(); i++)
    {
        size_t jacobPrev = (_jacob[i] == 1) ? 0 : _jacob[i - 1];

        for (size_t j = _jacob[i]; j > jacobPrev; j--)
        {
            if (j > pend.size())
                continue ;
            if (j == 1)
                it = mainchain.begin();
            else
                it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[j - 1]);
            if (!i_main.empty())
                i_main.insert(i_main.begin() + std::distance(mainchain.begin(), it), i_pend[j - 1]);
            mainchain.insert(it, pend[j - 1]);
        }
    }
}

void PmergeMe::display_array(std::string str)
{
    std::cout << str << ": ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void display_vec(std::vector<int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}
