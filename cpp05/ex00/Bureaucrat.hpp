#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>

#define MIN_GRADE 150
#define MAX_GRADE 1

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
