#include "Intern.hpp"

Intern::Intern()
{
	// std::cout << "Intern constructor called" << std::endl;
}

Intern::~Intern()
{
	// std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	(void)src;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

AForm	*Intern::makeForm(std::string const &name, std::string const &target)
{
	AForm		*result = NULL;
	std::string	formNames[] = 
	{
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm		*formObjects[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++) // i < formobject size()
	{
		if (name == formNames[i]) 
		{
			result = formObjects[i];
			std::cout << "Intern creates " << result->get_name() << " form." << std::endl;
		} 
		else 
			delete formObjects[i];
	}
	if (!result)
	{
		std::cout << name << " is not an official form." << std::endl;
	}
	return (result);
}
