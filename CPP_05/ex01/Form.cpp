#include "Form.hpp"

Form::Form()
: _name("defaultName"), _isSigned(false), _signGrade(150), _execGrade(150)
{
	std::cout << "Form constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form::Form(const Form &src)
: _name(src.get_name()), _isSigned(false), _signGrade(src.get_signGrade()), _execGrade(src.get_execGrade())
{ 
	std::cout << "Form copy constructor called" << std::endl; 
	*this = src;
}

Form	&Form::operator=(const Form &rhs)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return (*this);
}

Form::Form(std::string const &name, int const signGrade, int const execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (Form::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (Form::GradeTooLowException());
}

bool	Form::beSigned(Bureaucrat const &employee)
{
	if (employee.get_grade() <= this->_signGrade)
	{
		this->_isSigned = true;
		return (true);
	}
	else
		throw(Form::GradeTooLowException());
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low.");
}

std::string const	&Form::get_name() const { return (this->_name); }

int					Form::get_signGrade() const { return (this->_signGrade); }

int					Form::get_execGrade() const { return (this->_execGrade); }

bool				Form::get_isSigned() const
{ 
	if (_isSigned == true)
		return (true);
	return (false);
}

std::ostream &operator<<(std::ostream &o, Form const &form)
{
	o << "Form : " << form.get_name() << std::endl;
	o << "Signed : " << form.get_isSigned() << std::endl;
	o << "Required grade : " << form.get_signGrade() << std::endl;
	o << "Executable grade : " << form.get_execGrade() << std::endl;
	return (o);
}
