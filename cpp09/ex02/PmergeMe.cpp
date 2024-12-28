#include "PmergeMe.hpp"
void display_vec(std::vector<int> vec);

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(char **argv)
{
    setContainers_vec(argv);
    createJacobSequence();

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

int PmergeMe::jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
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

void PmergeMe::createJacobSequence()
{
    size_t size;
    size_t jcobstalIndex;
    int index;

    size = _vector.size();
    index = 3;

    while ((jcobstalIndex = jacobsthal(index)) < size - 1)
    {
        _jacobSequence.push_back(jcobstalIndex);
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

void PmergeMe::merge_insertion_sort(std::vector<int>& vec, std::vector<int>& indexes)
{
    if (vec.size() <= 1)
        return ;
    (void)indexes;

    std::vector<int>::iterator it = vec.begin();
    for (size_t i = 0; i < vec.size() / 2; i++)
    {
        if (*it < *(it + 1))
            std::iter_swap(it, it + 1);
        it += 2;
    }

    std::vector<int> mainchain, pend, subIndexes;
    set_mainchain_pend(vec, mainchain, pend);
    display_vec(mainchain);
    display_vec(pend);
    std::cout << std::endl;
    for (size_t i = 0; i < mainchain.size(); i++)
        subIndexes.push_back(i);
    
    merge_insertion_sort(mainchain, subIndexes);
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
