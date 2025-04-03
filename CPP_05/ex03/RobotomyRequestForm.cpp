#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	// std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
{ 
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl; 
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
: AForm::AForm("Robotomy", 72, 45), _target(target)
{
	// std::cout << "RobotomyRequestForm parameter constructor called" << std::endl;
}

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (get_isSigned() == false) 
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.get_grade() > this->get_execGrade()) 
    {
        throw AForm::GradeTooLowException();
    }
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1) 
	{
		std::cout << this->_target << " has been robotomized !" << std::endl;
	} else 
	{
		std::cout << this->_target << " couldn't be robotomized..." << std::endl;
	}
}
