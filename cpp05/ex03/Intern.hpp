#ifndef Intern_HPP
#define Intern_HPP

#include <iostream>
#include "AForm.hpp"

class AForm;

#define FORM_SHRUBBERY 0
#define FORM_ROBOTOMY 1
#define FORM_PRESIDENTIAL 2

class Intern
{
public:
    Intern();
    Intern(const Intern &copy);
    ~Intern();
    Intern &operator=(const Intern &copy);
    
    int getFormType(const std::string& name) const;
    AForm *makeForm(const std::string &name, const std::string &target);

    class FormNotExitException: public std::exception
    {
        const char *what() const throw();
    };
};

#endif