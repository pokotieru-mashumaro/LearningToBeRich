#include "PmergeMe.hpp"
void display_vec(std::vector<unsigned int> vec);

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(char **argv)
{
    setContainers(argv);
    display_array("before");

    std::vector<unsigned int> tmp(_vector.size());
    merge_insertion_sort_vector(tmp);

    display_array("after");
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

void PmergeMe::setContainers(char **argv)
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
        _deque.push_back(atoi(*argv));
        argv++;
    }
}

void PmergeMe::merge_insertion_sort_vector(std::vector<unsigned int> tmp)
{
    m_sort_vec(tmp, 0, tmp.size() - 1);
}


void PmergeMe::m_sort_vec(std::vector<unsigned int> tmp, int left, int right)
{
    int mid;
    if (right > left)
    {
        mid = (right + left) / 2;
        std::cout << "left: " << left << " mid: " << mid << std::endl;
        m_sort_vec(tmp, left, mid);
        std::cout << "mid + 1: " << mid + 1 << " right: " << right << std::endl;
        m_sort_vec(tmp, mid + 1, right);

        std::cout << "merge_vec" << std::endl;
        std::cout << "before: ";
        display_vec(_vector);
        merge_vec(left, mid + 1, right);
        std::cout << "after: ";
        display_vec(_vector);
    }
}

void PmergeMe::merge_vec(int left, int mid, int right)
{
    std::vector<unsigned int> left_array(_vector.begin() + left, _vector.begin() + mid);
    std::vector<unsigned int> right_array(_vector.begin() + mid, _vector.begin() + right + 1);

    size_t i = 0;
    size_t j = 0;
    size_t k = left;

    while (i < left_array.size() && j < right_array.size())
    {
        if (left_array[i] <= right_array[j])
        {
            _vector[k] = left_array[i];
            i++;
        }
        else
        {
            _vector[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < left_array.size())
    {
        _vector[k] = left_array[i];
        i++;
        k++;
    }

    while (j < right_array.size())
    {
        _vector[k] = right_array[j];
        j++;
        k++;
    }
}

void PmergeMe::display_array(std::string str)
{
    std::cout << str << ": ";
    for (size_t i = 0; i < _vector.size(); i++)
        std::cout << _vector[i] << " ";
    std::cout << std::endl;
}

void display_vec(std::vector<unsigned int> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}
