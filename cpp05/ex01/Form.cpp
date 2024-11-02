#include "Form.hpp"

Form::Form(const std::string& name, int grade_required_to_sign, int grade_required_to_execute)
: _name(name),
_is_signed(false),
_grade_required_to_sign(grade_required_to_sign),
_grade_required_to_execute(grade_required_to_execute)
{
    if (grade_required_to_sign > MIN_GRADE)
        throw GradeTooLowException();
    else if (grade_required_to_sign < MAX_GRADE)
        throw GradeTooHighException();

    if (grade_required_to_execute > MIN_GRADE)
        throw GradeTooLowException();
    else if (grade_required_to_execute < MAX_GRADE)
        throw GradeTooHighException();
}

Form::Form(const Form &copy)
: _name(copy._name),
_is_signed(false),
_grade_required_to_sign(copy._grade_required_to_sign),
_grade_required_to_execute(copy._grade_required_to_execute)
{
}

Form::~Form()
{
}

Form &Form::operator=(const Form &copy)
{
    if (this != &copy)
    {}
    return *this;
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return "Form: grageが低すぎます。";;
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return "Form: grageが高すぎます。";;
}

const std::string &Form::getName() const
{
    return this->_name;
}

bool Form::getSigned() const
{
	return _is_signed;
}

int	Form::getGradeSign() const
{
	return _grade_required_to_sign;
}

int	Form::getGradeExec() const
{
	return _grade_required_to_execute;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_grade_required_to_sign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_is_signed = true;
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
    o << "Name: " << form.getName() << ", is Signed: " << form.getSigned() << ", grade required to sign: " << form.getGradeSign() << ", grade required to execute: " << form.getGradeExec() << std::endl;
    return o;
}
