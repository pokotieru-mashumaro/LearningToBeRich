#ifndef   RobotomyRequestForm_HPP
#define   RobotomyRequestForm_HPP

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	const std::string _target;
public:
    RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &copy);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm &copy);

	virtual void execute(Bureaucrat const & executor);
};

std::ostream&	operator<<(std::ostream &o, const RobotomyRequestForm& aform);

#endif
