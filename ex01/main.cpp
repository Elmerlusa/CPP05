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
#include "Form.hpp"

int	main(void)
{
	try
	{
		Form		f("NanoForm", 0, 30);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Form		f("NanoForm", 10, 160);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("El Nano", 20);
		Form		f("NanoForm", 20, 30);

		std::cout << b << std::endl << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("El Nano", 20);
		Form		f("NanoForm", 21, 30);

		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b("El Nano", 20);
		Form		f("NanoForm", 19, 30);

		std::cout << f << std::endl;
		b.signForm(f);
		std::cout << f << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
