#pragma once

#include "Bureaucrat.hpp"

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_isSigned;
		int const			_signGrade;
		int const			_execGrade;

	public:
		AForm();
		virtual ~AForm();
		AForm(AForm const &src);
		AForm	&operator=(AForm const &rhs);

		AForm(std::string const &name, int const signGrade, int const execGrade);
		void	beSigned(Bureaucrat const &employee);
		virtual void	execute(Bureaucrat const &executor) const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		std::string const	get_name() const;
		bool				get_isSigned() const;
		int					get_signGrade() const;
		int					get_execGrade() const;

};

std::ostream	&operator<<(std::ostream &o, AForm const &form);
