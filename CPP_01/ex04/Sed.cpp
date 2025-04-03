/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcouserg <fcouserg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:16:51 by fcouserg          #+#    #+#             */
/*   Updated: 2024/11/24 18:52:12 by fcouserg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

void ft_replace(const std::string& inputFile, const std::string& s1, const std::string& s2)
{
	if (inputFile.empty() || s1.empty() || s2.empty()){
		std::cout << "Error: Empty string detected" << std::endl;
		return;
	}

	std::ifstream inFile(inputFile.c_str());
    if (!inFile.is_open()) {
        std::cout << "Error: file couldn't be opened " << std::endl;
        return;
    }

    std::string outputFile = inputFile + ".replace";
	std::ofstream outFile(outputFile.c_str());
    if (!outFile.is_open()) {
        std::cout << "Error: file couldn't be created " << std::endl;
        inFile.close();
        return;
    }

    std::string line;
	size_t pos = 0;
	if (getline(inFile, line, '\0')) 		
	{
		pos = line.find(s1);
		while (pos != std::string::npos)
		{
			line.erase(pos, s1.size());
			line.insert(pos, s2);
			pos = line.find(s1);
		}
		outFile << line;
		std::cout << "Success: file saved as: " << outputFile << std::endl;
	}
	else
		 std::cout << "Error: getline()" << std::endl;
	inFile.close();
	outFile.close();
}
