#ifndef   AForm_HPP
#define   AForm_HPP

#include <iostream>

# include "Bureaucrat.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class Bureaucrat;

class AForm
{
protected:
	const std::string _name;
	bool _is_signed;
	const int _grade_required_to_sign;
	const int _grade_required_to_execute;

    //デフォルトコンストラクタがない場合、継承先のコピーコンストラクタでエラーが発生するため
    AForm();

public:
    AForm(const std::string& name, int grade_required_to_sign, int grade_required_to_execute);
	AForm(const AForm &copy);
	virtual ~AForm();
	AForm&	operator=(const AForm &copy);

    const std::string&	getName() const;
	bool getSigned() const;
    int getGradeSign() const;
	int getGradeExec() const;

    void beSigned(const Bureaucrat& bureaucrat);

    virtual void execute(Bureaucrat const &executor) = 0;

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };

    class FormNotSignedException : public std::exception
	{
        const char *what() const throw();
	};
};

std::ostream&	operator<<(std::ostream &o, const AForm& aform);

#endif
