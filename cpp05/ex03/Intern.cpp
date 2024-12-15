#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{}

Intern::Intern(const Intern &copy) 
{
    *this = copy;
}

Intern::~Intern() 
{}

Intern &Intern::operator=(const Intern &copy) {
    if (this != &copy) 
    {}
    return *this;
}

int Intern::getFormType(const std::string& name) const
{

    if (name == "ShrubberyCreationForm")
        return FORM_SHRUBBERY;
    else if (name == "RobotomyRequestForm")
        return FORM_ROBOTOMY;
    else if (name == "PresidentialPardonForm")
        return FORM_PRESIDENTIAL;
    return -1;
}

const char *Intern::FormNotExitException::what() const throw()
{
    return "Intern: Formが存在しません";
}


AForm* Intern::makeForm(const std::string& name, const std::string& target) 
{
    AForm* form;

    switch (getFormType(name))
    {
    case FORM_SHRUBBERY:
        form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates ShrubberyCreationForm" << std::endl;
        break;
    case FORM_ROBOTOMY:
        form = new RobotomyRequestForm(target);
        std::cout << "Intern creates RobotomyRequestForm" << std::endl;
        break;
    case FORM_PRESIDENTIAL:
        form = new PresidentialPardonForm(target);
        std::cout << "Intern creates PresidentialPardonForm" << std::endl;
        break;
    default:
        throw FormNotExitException();
    }
    return form;
}

