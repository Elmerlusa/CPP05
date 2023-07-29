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

int	main(void)
{
	try
	{
		Bureaucrat				b("El Nano", 100);
		Bureaucrat				b2("Yo", 140);
		ShrubberyCreationForm	s("home");
		
		b.signForm(s);
		b.executeForm(s);
		std::cout << s << std::endl;
		b2.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat				b("El Nano", 40);
		Bureaucrat				b2("Yo", 140);
		RobotomyRequestForm		s("home");
		
		b.executeForm(s);
		b2.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat				b("El Nano", 1);
		Bureaucrat				b2("Yo", 140);
		PresidentialPardonForm	s("home");
		
		b.executeForm(s);
		b2.executeForm(s);
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
