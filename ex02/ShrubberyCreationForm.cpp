/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:18:02 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/28 13:18:02 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

void	ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	{
		std::ofstream	os((this->_target + "_shrubbery").c_str(), std::ios::out);

		if (os.is_open())
		{
			os 	<<	"(E)" << std::endl
				<<	"  `--(E+T)" << std::endl
				<<  "        `--(E)" << std::endl
				<<  "      |      `--(E+T)" << std::endl
				<<  "      |       `--(E)" << std::endl
				<<  "      |       |   `--(E+T)" << std::endl
				<<  "      |       |       `--(E)" << std::endl
				<<  "      |       |       |   `--(T)" << std::endl
				<<  "      |       |       |       `--[a]" << std::endl
				<<  "      |       |       `--[+]" << std::endl
				<<  "      |       |       `--(T)" << std::endl
				<<  "      |       |           `--(T*a)" << std::endl
				<<  "      |       |               `--(T)" << std::endl
				<<  "      |       |               |   `--(T*a)" << std::endl
				<<  "      |       |               |       `--(T)" << std::endl
				<<  "      |       |               |       |   `--[a]" << std::endl
				<<  "      |       |               |       `--[*]" << std::endl
				<<  "      |       |               |       `--[a]" << std::endl
				<<  "      |       |               `--[*]" << std::endl
				<<  "      |       |               `--[a]" << std::endl
				<<  "      |       `--[+]" << std::endl
				<<  "      |       `--(T)" << std::endl
				<<  "      |           `--[a]" << std::endl
				<<  "      `--[+]" << std::endl
				<<  "      `--(T)" << std::endl
				<<  "          `--[a]" << std::endl;
			if (os.bad())
				std::cout << "Couldn't write file" << std::endl;
		}
	}
}
