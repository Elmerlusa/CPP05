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

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("DefaultName", 145, 137), _target("nobody")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm):
	AForm(shrubberyCreationForm.getName(), shrubberyCreationForm.getSignGrade(), shrubberyCreationForm.getExecGrade()), _target(shrubberyCreationForm.getTarget())
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

const std::string&	ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

void	ShrubberyCreationForm::realExecute(void) const
{
	std::ofstream	os((this->_target + "_shrubbery").c_str(), std::ios::out);

	if (os.is_open())
	{
		os 	<<	"(E)\n"
			<<	"  `--(E+T)\n"
			<<  "        `--(E)\n"
			<<  "      |      `--(E+T)\n"
			<<  "      |       `--(E)\n"
			<<  "      |       |   `--(E+T)\n"
			<<  "      |       |       `--(E)\n"
			<<  "      |       |       |   `--(T)\n"
			<<  "      |       |       |       `--[a]\n"
			<<  "      |       |       `--[+]\n"
			<<  "      |       |       `--(T)\n"
			<<  "      |       |           `--(T*a)\n"
			<<  "      |       |               `--(T)\n"
			<<  "      |       |               |   `--(T*a)\n"
			<<  "      |       |               |       `--(T)\n"
			<<  "      |       |               |       |   `--[a]\n"
			<<  "      |       |               |       `--[*]\n"
			<<  "      |       |               |       `--[a]\n"
			<<  "      |       |               `--[*]\n"
			<<  "      |       |               `--[a]\n"
			<<  "      |       `--[+]\n"
			<<  "      |       `--(T)\n"
			<<  "      |           `--[a]\n"
			<<  "      `--[+]\n"
			<<  "      `--(T)\n"
			<<  "          `--[a]" << std::endl;
		if (os.bad())
			std::cout << "Couldn't write file" << std::endl;
		os.close();
	}
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& shrubberyCreationForm)
{
	if (this != &shrubberyCreationForm)
		std::cout << "Assignment operation is impossible: const values of base class cannot be overwritten" << std::endl;
	return *this;
}
