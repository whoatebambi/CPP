#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Mark = Bureaucrat("Mark", 1); // 50
		Intern someRandomIntern;

		AForm* form1 = someRandomIntern.makeForm("robotomy request", "target");
		Mark.signForm(form1);
		Mark.executeForm(form1);
		delete(form1);

		AForm* form2 = someRandomIntern.makeForm("shrubbery creation", "target");
		Mark.signForm(form2);
		Mark.executeForm(form2);
		delete(form2);

		AForm* form3 = someRandomIntern.makeForm("presidential pardon", "target");
		Mark.signForm(form3);
		Mark.executeForm(form3);
		delete(form3);

		AForm* form4 = someRandomIntern.makeForm("bubble destruction", "target");
		Mark.signForm(form4);
		Mark.executeForm(form4);
		delete(form4);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
