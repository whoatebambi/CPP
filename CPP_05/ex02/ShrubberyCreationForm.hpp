#pragma once

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;

	public:
		ShrubberyCreationForm();
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);

		ShrubberyCreationForm(std::string const &target);
		void	execute(Bureaucrat const & executor) const;
};
