#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class AForm;

class Intern
{
	private:

	public:
		Intern();
		~Intern();
		Intern(Intern const &src);
		Intern	&operator=(Intern const &rhs);

		AForm	*makeForm(std::string const &name, std::string const &target);
};
