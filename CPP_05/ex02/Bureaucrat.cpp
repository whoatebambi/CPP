#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
: _name("defaultName"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
: _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs.get_grade();
	}
	return (*this);
}

Bureaucrat::Bureaucrat(std::string const &name, int grade)
: _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooLowException();
	if (grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::incrGrade()
{
	this->_grade -= 1;
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrGrade()
{
	this->_grade += 1;
	if (this->_grade > 150)
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.get_name() << std::endl;
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << this->_name << " couldn't sign " << form.get_name() << " because " 
		<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << get_name() << " executed " << form.get_name() << " form." << std::endl;
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cerr << get_name() << " couldn't execute " << form.get_name() << " because " << e.what() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw() { return ("Grade is too high."); }

const char *Bureaucrat::GradeTooLowException::what() const throw() { return ("Grade is too low."); }

std::string const	&Bureaucrat::get_name() const { return (this->_name); }

int					Bureaucrat::get_grade() const { return (this->_grade); }

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs)
{
	o << rhs.get_name() << ", bureaucrat grade " << rhs.get_grade() << "." << std::endl;
	return (o);
}
