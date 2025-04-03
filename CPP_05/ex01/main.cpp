#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Mark = Bureaucrat("Mark", 1); // 150
		std::cout << Mark << std::endl;
		Form form42 = Form("FORM_42", 15, 10);
		Mark.signForm(form42);
		std::cout << form42 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
