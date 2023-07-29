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

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	t_forms	forms[] = {
		{"shrubbery creation", new ShruberryCreationForm(target)},
		{"robotomy request", new RobotomyRequestForm(target)},
		{"presidential pardon", new PresidentialPardonForm(target)},
		{"", NULL}
	};
	int		forms_len = end(forms) - begin(forms);
	AForm	*form = NULL;

	for (int i = 0; i < forms_len; i++)
	{
		if (strcmp(formName, forms[i].name) == 0)
			form = forms[i].form;
		else
			delete forms[i].form;
	}
	if (form == NULL)
		std::cout << "Any " << formName << " exists" << std::endl;
	else
		std::cout << "Intern creates " << formName << std::endl;
	return form;
}
