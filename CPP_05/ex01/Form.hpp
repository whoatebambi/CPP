#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;

	public:
		Form();
		~Form();
		Form(Form const &src);
		Form	&operator=(Form const &rhs);

		Form(std::string const &name, int const signGrade, int const execGrade);
		bool	beSigned(Bureaucrat const &employee);

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
		bool				get_isSigned() const;
		int					get_signGrade() const;
		int					get_execGrade() const;

};

std::ostream	&operator<<(std::ostream &o, Form const &form);