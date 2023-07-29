/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:37:43 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/25 17:37:43 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string name, int signGrade, int execGrade):
	_name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	this->_signed = false;
}

Form::~Form(void)
{
}

std::string	Form::getName(void) const
{
	return this->_name;
}

bool	Form::getSigned(void) const
{
	return this->_signed;
}

int	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

int	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

const char*	Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char*	Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& ostr, const Form& form)
{
	return ostr << "Form(" << form.getName() << ", " << form.getSigned()
		<< ", " << form.getSignGrade() << ", " << form.getExecGrade()
		<< ")";
}
