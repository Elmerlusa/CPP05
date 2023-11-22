/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:23:50 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 15:23:50 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern& intern)
{
	(void) intern;
}

Intern::~Intern(void)
{
}

AForm*	Intern::createShrubberyForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(const std::string& formName, const std::string& target) const
{
	std::string	formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon", ""};
	AForm*		(Intern::*createForm[])(const std::string& target) const = {&Intern::createShrubberyForm, &Intern::createRobotomyForm, &Intern::createPresidentialForm, NULL};

	for (int i = 0; formNames[i].empty() == false; i++)
	{
		if (formName.compare(formNames[i]) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (this->*createForm[i])(target);
		}
	}
	std::cout << "Any form called " << formName << " exists" << std::endl;
	return NULL;
}

Intern&	Intern::operator=(const Intern& intern)
{
	(void) intern;
	return *this;
}
