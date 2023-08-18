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

Intern::~Intern(void)
{
}


AForm*	createShrubberyForm(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm*	createRobotomyForm(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm*	createPresidentialForm(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm*	Intern::makeForm(std::string formName, std::string target) const
{
	t_form_map	forms[] = {
		{"shrubbery creation", &createShrubberyForm},
		{"robotomy request", &createRobotomyForm},
		{"presidential pardon", &createPresidentialForm},
		{"", NULL}
	};

	for (int i = 0; forms[i].f != NULL; i++)
	{
		if (formName.compare(forms[i].name) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].f(target);
		}
	}
	std::cout << "Any " << formName << " exists" << std::endl;
	return NULL;
}
