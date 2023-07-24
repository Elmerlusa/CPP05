/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 23:11:26 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/12 23:11:26 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	std::cout << "New grade " << grade << std::endl;
	if (grade < MAX_GRADE)
		throw(GradeTooHighException());
	if (grade > MIN_GRADE)
		throw(GradeTooLowException());
	this->_grade = grade;
	std::cout << "Bureaucrat " << name << " constructed" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destructed" << std::endl;
}

std::string	Bureaucrat::getName(void) const
{
	return this->_name;
}

int	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "New grade " << this->_grade - 1 << std::endl;
	if (this->_grade - 1 < MAX_GRADE)
		throw(GradeTooHighException());
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "New grade " << this->_grade + 1 << std::endl;
	if (this->_grade + 1 > MIN_GRADE)
		throw(GradeTooLowException());
	this->_grade = this->_grade + 1;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat's grade cannot be under 1";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat's grade cannot be over 150";
}

std::ostream&	operator<<(std::ostream& ostr, const Bureaucrat& bureaucrat)
{
	return ostr << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
