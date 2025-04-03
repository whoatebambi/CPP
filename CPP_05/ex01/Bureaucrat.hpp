#pragma once

#include "Form.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class Form;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;

	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat	&operator=(Bureaucrat const &rhs);

		Bureaucrat(std::string const &name, int grade);
		void	incrGrade();
		void	decrGrade();
		void	signForm(Form &form);

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string const	&get_name() const;
		int					get_grade() const;

};

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &rhs);
