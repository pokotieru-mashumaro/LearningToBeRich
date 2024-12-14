# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target): AForm("RobotomyRequestForm", 72, 45), _target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy)
{
	if (this != &copy)
	{}
	return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    if (executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());

	srand(time(NULL));
	if (rand() % 2)
		std::cout << _target << " has been robotimized successfully" << std::endl;
	else
		std::cout << "the robotomy failed!" << std::endl;
}

std::ostream& operator<<(std::ostream &o, const RobotomyRequestForm& aform)
{
    o << "Name: " << aform.getName() << ", is Signed: " << aform.getSigned() << ", grade required to sign: " << aform.getGradeSign() << ", grade required to execute: " << aform.getGradeExec() << std::endl;
    return o;
}
