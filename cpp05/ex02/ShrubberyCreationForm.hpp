#ifndef   ShrubberyCreationForm_HPP
#define   ShrubberyCreationForm_HPP

# include <fstream>

# include "AForm.hpp"

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;
public:
    ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &copy);
	~ShrubberyCreationForm();
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm &copy);

	void execute(Bureaucrat const & executor);
};

std::ostream&	operator<<(std::ostream &o, const ShrubberyCreationForm& aform);

#endif
