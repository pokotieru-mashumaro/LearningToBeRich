#include "AForm.hpp"

AForm::AForm(void): _name("default"), _is_signed(false), _grade_required_to_sign(1), _grade_required_to_execute(1)
{}

AForm::AForm(const std::string& name, int grade_required_to_sign, int grade_required_to_execute)
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

AForm::AForm(const AForm &copy)
: _name(copy._name),
_is_signed(false),
_grade_required_to_sign(copy._grade_required_to_sign),
_grade_required_to_execute(copy._grade_required_to_execute)
{
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy)
    {}
    return *this;
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return "AForm: grageが低すぎます。";
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return "AForm: grageが高すぎます。";
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return "AForm: Formにサインされていません";
}

const std::string &AForm::getName() const
{
    return this->_name;
}

bool AForm::getSigned() const
{
	return _is_signed;
}

int	AForm::getGradeSign() const
{
	return _grade_required_to_sign;
}

int	AForm::getGradeExec() const
{
	return _grade_required_to_execute;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->_grade_required_to_sign < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->_is_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	(void)executor;
}

std::ostream &operator<<(std::ostream &o, const AForm &aform)
{
    o << "Name: " << aform.getName() << ", is Signed: " << aform.getSigned() << ", grade required to sign: " << aform.getGradeSign() << ", grade required to execute: " << aform.getGradeExec() << std::endl;
    return o;
}
