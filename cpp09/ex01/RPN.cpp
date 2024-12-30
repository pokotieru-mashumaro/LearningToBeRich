#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(std::string str)
{
    calculate(str);
    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    display();
}

RPN::RPN(const RPN &copy)
{
    *this = copy;
}

RPN &RPN::operator=(const RPN &copy)
{
    if (this != &copy)
    {
        this->_stack = copy._stack;
    }
    return *this;
}

RPN::~RPN()
{}

void RPN::calculate(std::string str)
{
    std::string token;
    std::stringstream ss(str);
    while (ss >> token)
    {
        if (token == "+")
            plus();
        else if (token == "-")
            minus();
        else if (token == "*")
            multiplied();
        else if (token == "/")
            divided();
        else if (token.size() > 1)
        {
            std::cerr << "Error" << std::endl;
            exit(1);
        }
        else
            _stack.push(atoi(token.c_str()));
    }
}

void RPN::plus()
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();

    long tmp = b + a;
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    _stack.pop();
    _stack.push(b + a);
}

void RPN::minus()
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();

    long tmp = b - a;
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    _stack.pop();
    _stack.push(b - a);
}

void RPN::multiplied()
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();

    long tmp = b * a;
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    _stack.pop();
    _stack.push(b * a);
}

void RPN::divided()
{
    if (_stack.size() < 2)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();

    long tmp = b / a;
    if (tmp > INT_MAX || tmp < INT_MIN)
    {
        std::cerr << "Error" << std::endl;
        exit(1);
    }

    _stack.pop();
    _stack.push(b / a);
}

void RPN::display()
{
    std::cout << _stack.top() << std::endl;
}
