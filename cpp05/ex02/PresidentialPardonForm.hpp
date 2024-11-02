#ifndef   PresidentialPardonForm_HPP
#define   PresidentialPardonForm_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	const std::string _target;
public:
    PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &copy);
	~PresidentialPardonForm();
	PresidentialPardonForm&	operator=(const PresidentialPardonForm &copy);

	void execute(Bureaucrat const & executor);
};

std::ostream&	operator<<(std::ostream &o, const PresidentialPardonForm& aform);

#endif
