#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
{ 
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl; 
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "ShrubberyCreationForm assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
: AForm::AForm("Shrubbery", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parameter constructor called" << std::endl;
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (get_isSigned() == false)
		throw AForm::FormNotSignedException();
	if (executor.get_grade() > this->get_execGrade()) 
		throw AForm::GradeTooLowException();
	std::string outf = this->_target + "_shrubbery";
	std::ofstream ofstrm(outf.c_str());
	if (!ofstrm.is_open())
	{
		std::cout << "Error opening or creating " << outf << " file." << std::endl;
		return ;
	}
	ofstrm <<   " ^  ^  ^   ^      ___I_      ^  ^   ^  ^  ^   ^  ^  \n"
				"/|\\/|\\/|\\ /|\\    /\\-_--\\    /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
				"/|\\/|\\/|\\ /|\\   /  \\_-__\\   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n"
				"/|\\/|\\/|\\ /|\\   |[]| [] |   /|\\/|\\ /|\\/|\\/|\\ /|\\/|\\ \n";
	ofstrm.close();
	std::cout << outf << " printed a little house in a pine forest" << std::endl;
}
