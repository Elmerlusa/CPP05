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
#include <stdexcept>

int	main(void)
{
	try
	{
		Bureaucrat	b1("El Nano", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("El Nano", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("El Nano", 1);

		std::cout << b1 << std::endl;
		b1.incrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("El Nano", 150);

		std::cout << b1 << std::endl;
		b1.decrementGrade();
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------" << std::endl;
	try
	{
		Bureaucrat	b1("El Nano", 10);

		std::cout << b1 << std::endl;
		b1.incrementGrade();
		std::cout << b1 << std::endl;
		b1.decrementGrade();
		std::cout << b1 << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return (0);
}
