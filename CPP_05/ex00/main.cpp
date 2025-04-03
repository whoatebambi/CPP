#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		// TOO HIGH
		Bureaucrat Mark1 = Bureaucrat("Mark1", 2); // 20
		std::cout << Mark1 << std::endl;
		Mark1.incrGrade();
		std::cout << Mark1 << std::endl;
		Mark1.incrGrade();
		std::cout << Mark1 << std::endl;

		// TOO LOW
		Bureaucrat Mark2 = Bureaucrat("Mark2", 149); // 14
		std::cout << Mark2 << std::endl;
		Mark2.decrGrade();
		std::cout << Mark2 << std::endl;
		Mark2.decrGrade();
		std::cout << Mark2 << std::endl;

		// INVALID
		Bureaucrat Mark3 = Bureaucrat("Mark3", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
