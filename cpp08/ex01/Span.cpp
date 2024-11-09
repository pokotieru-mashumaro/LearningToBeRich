# include "Span.hpp"

Span::Span(): _N(0)
{}

Span::Span(unsigned int N): _N(N), _index(0)
{
    _arr = new int[N];
}

Span::Span(const Span &copy)
{
    *this = copy;
}

Span::~Span()
{
    delete [] _arr;
}

Span &Span::operator=(const Span &copy)
{
    if (this != &copy)
    {
        this->_N = copy._N;
        this->_index = copy._index;
        this->_arr = copy._arr;
    }
    return *this;
}

void Span::addNumber(int value)
{
    if (_index == _N)
        throw AlreadyStoredException() ;
    _arr[_index] = value;
    _index++;
}

void Span::addNumbers(unsigned int end)
{
    for (unsigned int i = 0; i < end; i++)
    {
        if (i > _N)
            throw AlreadyStoredException();
        _arr[i] = i;
    }
    _index = end - 1;
}



long Span::shortestSpan(void)
{
    long ret = 2147483647 + 2147483648;

    if (_index <= 1)
        throw NoSpanException();

    for (unsigned int i = 0; i < _index; i++)
    {
        for (unsigned int j = i + 1; j < _index; j++)
        {
            int val = _arr[i] > _arr[j] ? _arr[i] - _arr[j] : _arr[j] - _arr[i];
            if (ret > val)
                ret = val;
        }
    }
    return ret;
}

long Span::longestSpan(void)
{
    int max_val, min_val;

    if (_index <= 1)
        throw NoSpanException();
    max_val = _arr[0] > _arr[1] ? _arr[0] : _arr[1];
    min_val = _arr[0] > _arr[1] ? _arr[1] : _arr[0];
    for (unsigned int i = 2; i < _N; i++)
    {
        int value = _arr[i];
        if (max_val < value)
            max_val = value;
        else if (min_val > value)
            min_val = value;
    }
    return max_val - min_val;
}

void Span::display_arr(void)
{
    for (unsigned int i = 0; i < _N; i++)
    {
        std::cout << i << "番目: " << _arr[i] << std::endl;
    }
}

const char *Span::AlreadyStoredException::what() const throw()
{
    return "already N elements stored";
}

const char *Span::NoSpanException::what() const throw()
{
    return "no span";
}
