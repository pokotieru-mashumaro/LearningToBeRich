#ifndef   Span_HPP
#define   Span_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class Span
{
private:
    Span();

    unsigned int _N;
    unsigned int _index;
    int *_arr;

public:
    Span(unsigned int N);
	Span(const Span &copy);
	~Span();
	Span& operator=(const Span &copy);

    void addNumber(int value);
    void addNumbers(unsigned int end);
    long shortestSpan(void);
    long longestSpan(void);

    void display_arr(void);

    class AlreadyStoredException : public std::exception
    {
        const char *what() const throw();
    };

    class NoSpanException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif