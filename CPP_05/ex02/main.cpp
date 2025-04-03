#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Mark = Bureaucrat("Mark", 1); // try 26
		std::cout << Mark << std::endl;

		PresidentialPardonForm form1 = PresidentialPardonForm("target");
		Mark.signForm(form1); // comment here
		Mark.executeForm(form1);
		std::cout << form1 << std::endl;

		// ShrubberyCreationForm form2 = ShrubberyCreationForm("target");
		// Mark.signForm(form2);
		// Mark.executeForm(form2);
		// std::cout << form2 << std::endl;

		// RobotomyRequestForm form3 = RobotomyRequestForm("target");
		// Mark.signForm(form3);
		// Mark.executeForm(form3);
		// std::cout << form3 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
