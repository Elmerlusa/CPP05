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
	if (grade < MAX_GRADE)
		throw(GradeTooHighException());
	if (grade > MIN_GRADE)
		throw(GradeTooLowException());
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat(void)
{
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
	if (this->_grade - 1 < MAX_GRADE)
		throw GradeTooHighException();
	this->_grade = this->_grade - 1;
}

void	Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > MIN_GRADE)
		throw GradeTooLowException();
	this->_grade = this->_grade + 1;
}

void	Bureaucrat::signForm(AForm& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't sign " << form.getName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form)
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
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
