#include "AForm.hpp"

AForm::AForm() : _name("doNotUse"), _isSigned(false), _signGrade(0), _execGrade(0)
{
	std::cout << "AForm constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm::AForm(const AForm &src)
: _name(src.get_name()), _isSigned(false), _signGrade(src.get_signGrade()), _execGrade(src.get_execGrade())
{ 
	std::cout << "AForm copy constructor called" << std::endl; 
	*this = src;
}

AForm	&AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &rhs)
		this->_isSigned = rhs._isSigned;
	return (*this);
}

AForm::AForm(std::string const &name, int const signGrade, int const execGrade)
: _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw (AForm::GradeTooHighException());
	else if (signGrade > 150 || execGrade > 150)
		throw (AForm::GradeTooLowException());
}

void	AForm::beSigned(Bureaucrat const &employee)
{	
	if (employee.get_grade() > this->_signGrade)
		throw(AForm::GradeTooLowException());
	this->_isSigned = true;
}

const char *AForm::GradeTooHighException::what() const throw() { return ("Grade is too high."); }

const char *AForm::GradeTooLowException::what() const throw() { return ("Grade is too low."); }

const char *AForm::FormNotSignedException::what() const throw() { return ("Form not signed."); }

std::string const	&AForm::get_name() const { return (this->_name); }

int					AForm::get_signGrade() const { return (this->_signGrade); }

int					AForm::get_execGrade() const { return (this->_execGrade); }

bool				AForm::get_isSigned() const
{ 
	if (_isSigned == true)
		return (true);
	return (false);
}

std::ostream &operator<<(std::ostream &o, AForm const &form)
{
	o << "Form : " << form.get_name() << std::endl;
	o << "Signed : " << form.get_isSigned() << std::endl;
	o << "Required grade : " << form.get_signGrade() << std::endl;
	o << "Executable grade : " << form.get_execGrade() << std::endl;
	return (o);
}
