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
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    _stack.push(b + a);
}

void RPN::minus()
{
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    _stack.push(b - a);
}

void RPN::multiplied()
{
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    _stack.push(b * a);
}

void RPN::divided()
{
    int a = _stack.top();
    _stack.pop();
    int b = _stack.top();
    _stack.pop();
    _stack.push(b / a);
}

void RPN::display()
{
    std::cout << _stack.top() << std::endl;
}
