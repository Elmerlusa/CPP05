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

Bureaucrat::Bureaucrat(void): _name("DefaultName"), _grade(MIN_GRADE)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& bureaucrat): _name(bureaucrat.getName()), _grade(bureaucrat.getGrade())
{
}

Bureaucrat::Bureaucrat(const std::string& name, const int& grade): _name(name)
{
	std::cout << "New grade " << grade << std::endl;
	if (grade < MAX_GRADE)
		throw GradeTooHighException();
	if (grade > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade = grade;
	std::cout << "Bureaucrat " << name << " constructed" << std::endl;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat " << this->_name << " destructed" << std::endl;
}

const std::string&	Bureaucrat::getName(void) const
{
	return this->_name;
}

const int&	Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void)
{
	std::cout << "New grade " << this->_grade - 1 << std::endl;
	if (this->_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::decrementGrade(void)
{
	std::cout << "New grade " << this->_grade + 1 << std::endl;
	if (this->_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade = this->_grade + 1;
}

void	Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because its " << e.what() << std::endl;
	}
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& bureaucrat)
{
	if (this != &bureaucrat)
	{
		this->_name = bureaucrat.getName();
		this->_grade = bureaucrat.getGrade();
	}
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "Bureaucrat's grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "Bureaucrat's grade is too low";
}

std::ostream&	operator<<(std::ostream& ostr, const Bureaucrat& bureaucrat)
{
	return ostr << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}
