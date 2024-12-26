#pragma once

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>

class RPN
{
private:
    RPN();
    RPN(const RPN &copy);
    RPN &operator=(const RPN &copy);

    std::stack<int> _stack;

    void plus();
    void minus();
    void multiplied();
    void divided();

public:
    RPN(std::string str);
    ~RPN();

    void calculate(std::string str);
    void display();
};
