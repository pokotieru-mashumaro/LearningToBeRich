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
    _index = end;
}

long Span::shortestSpan(void)
{
    if (_index <= 1)
        throw NoSpanException();

    std::vector<int> temp(_arr, _arr + _index);
    std::sort(temp.begin(), temp.end());
    
    long min_span = static_cast<long>(temp[1]) - static_cast<long>(temp[0]);
    for (unsigned int i = 1; i < _index - 1; ++i)
    {
        long span = static_cast<long>(temp[i + 1]) - static_cast<long>(temp[i]);
        if (span < min_span)
            min_span = span;
    }
    return min_span;
}

long Span::longestSpan(void)
{
    if (_index <= 1)
        throw NoSpanException();

    int* min = std::min_element(_arr, _arr + _index);
    int* max = std::max_element(_arr, _arr + _index);
    return static_cast<long>(*max) - static_cast<long>(*min);
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
