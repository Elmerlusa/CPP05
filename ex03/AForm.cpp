/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:37:43 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/25 17:37:43 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void): _name("DefaultAFormName"), _signed(false), _signGrade(MAX_GRADE), _execGrade(MAX_GRADE)
{
}

AForm::AForm(const AForm& form): _name(form.getName()), _signed(form.getSigned()), _signGrade(form.getSignGrade()), _execGrade(form.getExecGrade())
{
}

AForm::AForm(const std::string& name, const int& signGrade, const int& execGrade):
	_name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < MAX_GRADE || execGrade < MAX_GRADE)
		throw GradeTooHighException();
	if (signGrade > MIN_GRADE || execGrade > MIN_GRADE)
		throw GradeTooLowException();
	std::cout << "AForm " << name << " constructed" << std::endl;
}

AForm::~AForm(void)
{
	std::cout << "AForm " << this->_name << " destructed" << std::endl;
}

const std::string&	AForm::getName(void) const
{
	return this->_name;
}

const bool&	AForm::getSigned(void) const
{
	return this->_signed;
}

const int&	AForm::getSignGrade(void) const
{
	return this->_signGrade;
}

const int&	AForm::getExecGrade(void) const
{
	return this->_execGrade;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	this->_signed = true;
}

void	AForm::execute(Bureaucrat const& executor) const
{
	if (this->_signed == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->_execGrade)
		throw GradeTooLowException();
	this->realExecute();
}

AForm&	AForm::operator=(const AForm& form)
{
	if (this != &form)
		std::cout << "Assignment operation is impossible: const values cannot be overwritten" << std::endl;
	return *this;
}

const char* AForm::FormNotSignedException::what(void) const throw()
{
	return "Form not signed";
}

const char*	AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& ostr, const AForm& form)
{
	return ostr << "AForm(" << form.getName() << ", " << form.getSigned()
		<< ", " << form.getSignGrade() << ", " << form.getExecGrade()
		<< ")";
}
