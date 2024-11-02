#ifndef   Form_HPP
#define   Form_HPP

#include <iostream>

# include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Form 
{
protected:
	const std::string _name;
	bool _is_signed;
	const int _grade_required_to_sign;
	const int _grade_required_to_execute;

public:
    Form(const std::string& name, int grade_required_to_sign, int grade_required_to_execute);
	Form(const Form &copy);
	~Form();
	Form&	operator=(const Form &copy);

    const std::string&	getName() const;
	bool getSigned() const;
    int getGradeSign() const;
	int getGradeExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream&	operator<<(std::ostream &o, const Form& Form);

#endif
