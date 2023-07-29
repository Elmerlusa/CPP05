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
	AForm*	form1;
	AForm*	form2;
	AForm*	form3;
	Bureaucrat	b("ElNano", 1);

	form1 = i.makeForm(":)", ":)");
	std::cout << form1 << std::endl;
	std::cout << "--------------------------------------------------" << std::endl;
	form1 = i.makeForm("shrubbery creation", "Home");
	if (form1 != NULL)
	{
		b.signForm(*form1);
		b.executeForm(*form1);
		std::cout << *form1 << std::endl;
	}
	// delete form1;
	std::cout << "--------------------------------------------------" << std::endl;
	form2 = i.makeForm("robotomy request", "Bender");
	if (form2 != NULL)
	{
		b.signForm(*form2);
		b.executeForm(*form2);
		std::cout << *form2 << std::endl;
	}
	// delete form2;
	std::cout << "--------------------------------------------------" << std::endl;
	form3 = i.makeForm("presidential pardon", "YES");
	if (form3 != NULL)
	{
		b.executeForm(*form3);
		std::cout << *form3 << std::endl;
	}
	// delete form3;
}
