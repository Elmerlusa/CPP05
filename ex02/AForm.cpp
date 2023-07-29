/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 12:57:36 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/28 12:57:36 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string name, int signGrade, int execGrade):
	_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	this->_signed = false;
}

AForm::~AForm(void)
{
}

std::string	AForm::getName(void) const
{
	return this->_name;
}

bool	AForm::getSigned(void) const
{
	return this->_signed;
}

int	AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

int	AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	else
		this->_signed = true;
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "AForm's grade is too high";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "AForm's grade is too low";
}

std::ostream&	operator<<(std::ostream& ostr, const AForm& form)
{
	return ostr << "AForm(" << form.getName() << ", " << form.getSigned()
		<< ", " << form.getSignGrade() << ", " << form.getExecGrade()
		<< ")";
}
