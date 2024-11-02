#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

#include "AForm.hpp"

#define MIN_GRADE 150
#define MAX_GRADE 1

class AForm;

class Bureaucrat
{
private:
    const std::string _name;
    int _grade;

public:
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    ~Bureaucrat();
    Bureaucrat &operator=(const Bureaucrat &copy);

    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();

    void signForm(AForm& aform) const;

    void	executeForm(AForm &form) const;

    class GradeTooLowException : public std::exception
    {
        const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw();
    };
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &bureaucrat);

#endif
