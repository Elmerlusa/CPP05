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

Form::Form(void): _name("DefaultFormName"), _signed(false), _signGrade(MAX_GRADE), _execGrade(MAX_GRADE)
{
}

Form::Form(const Form& form): _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _execGrade(form.getExecGrade())
{
}

Form::Form(const std::string& name, const int& signGrade, const int& execGrade):
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << "Form " << name << " constructed" << std::endl;
}

Form::~Form(void)
{
	std::cout << "Form " << this->_name << " destructed" << std::endl;
}

const std::string&	Form::getName(void) const
{
	return this->_name;
}

const bool&	Form::getSigned(void) const
{
	return this->_signed;
}

const int&	Form::getSignGrade(void) const
{
	return this->_signGrade;
}

const int&	Form::getExecGrade(void) const
{
	return this->_execGrade;
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

Form&	Form::operator=(const Form& form)
{
	if (this != &form)
		std::cout << "Assignment operation is impossible: const values cannot be overwritten" << std::endl;
	return *this;
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
