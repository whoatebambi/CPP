/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 19:23:36 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2) 
	{
		std::cout << "Usage: ./harl [LEVEL]" << std::endl;
		std::cout  << "LEVEL = [DEBUG || INFO || WARNING || ERROR]" << std::endl;
		return (1);
	}
	Harl	harly;
	harly.complain(argv[1]);
	return (0);
}

// int	main(void){
// 	Harl harl;
// 	harl.complain("DEBUG");
// 	harl.complain("INFO");
// 	harl.complain("WARNING");
// 	harl.complain("ERROR");
// 	harl.complain("COMPLAIN");
// }
