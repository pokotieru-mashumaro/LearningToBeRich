#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
    if (grade > MIN_GRADE)
        throw GradeTooLowException();
    else if (grade < MAX_GRADE)
        throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    *this = copy;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
    if (this != &copy)
    {
        this->_grade = copy._grade;
    }
    return *this;
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "grageが低すぎます。";;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "grageが高すぎます。";;
}

const std::string &Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const
{
    return this->_grade;
}

void Bureaucrat::incrementGrade()
{
    if (_grade - 1 < MAX_GRADE)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > MIN_GRADE)
        throw GradeTooLowException();
    _grade += 1;
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat)
{
    o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
    return o;
}