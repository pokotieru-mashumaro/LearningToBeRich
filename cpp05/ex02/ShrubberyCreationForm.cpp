# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): AForm("ShrubberyCreationForm", 145, 137), _target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy)
{
	if (this != &copy)
	{}
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	if ((int)executor.getGrade() > this->getGradeExec())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == false)
		throw (AForm::FormNotSignedException());

	std::ofstream file(_target + "_shrubbery");
    if (file.is_open()) {
        file << "     *\n";
        file << "    ***\n";
        file << "   *****\n";
        file << "  *******\n";
        file << " *********\n";
        file << "    |||\n";
        file.close();
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

std::ostream&	operator<<(std::ostream &o, const ShrubberyCreationForm& aform)
{
    o << "Name: " << aform.getName() << ", is Signed: " << aform.getSigned() << ", grade required to sign: " << aform.getGradeSign() << ", grade required to execute: " << aform.getGradeExec() << std::endl;
    return o;
}

