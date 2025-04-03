#pragma once

#include "AForm.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		~PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const &src);
		PresidentialPardonForm	&operator=(PresidentialPardonForm const &rhs);

		PresidentialPardonForm(const std::string &target);
		void	execute(Bureaucrat const &executor) const;
};
