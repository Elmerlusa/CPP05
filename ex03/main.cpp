/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:11:45 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/12 23:11:45 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	Intern	i;
	AForm*	form;
	Bureaucrat	b("ElNano", 1);

	form = i.makeForm(":)", ":)");
	std::cout << "--------------------------------------------------" << std::endl;
	form = i.makeForm("shrubbery creation", "Home");
	if (form != NULL)
	{
		b.signForm(*form);
		b.executeForm(*form);
		std::cout << *form << std::endl;
	}
	delete form;
	std::cout << "--------------------------------------------------" << std::endl;
	form = i.makeForm("robotomy request", "Bender");
	if (form != NULL)
	{
		b.signForm(*form);
		b.executeForm(*form);
		std::cout << *form << std::endl;
	}
	delete form;
	std::cout << "--------------------------------------------------" << std::endl;
	form = i.makeForm("presidential pardon", "YES");
	if (form != NULL)
	{
		b.executeForm(*form);
		b.signForm(*form);
		b.executeForm(*form);
		std::cout << *form << std::endl;
	}
	delete form;
}
