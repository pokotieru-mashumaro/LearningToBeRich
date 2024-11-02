# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target): AForm("PresidentialPardonForm", 25, 5), _target(target)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& copy)
{
	if (this != &copy)
	{}
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream&	operator<<(std::ostream &o, const PresidentialPardonForm& aform)
{
    o << "Name: " << aform.getName() << ", is Signed: " << aform.getSigned() << ", grade required to sign: " << aform.getGradeSign() << ", grade required to execute: " << aform.getGradeExec() << std::endl;
    return o;
}
