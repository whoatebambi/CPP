#pragma once

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		~RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const &src);
		RobotomyRequestForm	&operator=(RobotomyRequestForm const &rhs);

		RobotomyRequestForm(std::string const &target);
		void	execute(Bureaucrat const & executor) const;
};
