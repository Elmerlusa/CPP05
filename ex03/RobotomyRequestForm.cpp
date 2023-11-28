/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:43:00 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 14:43:00 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("DefaultName", 72, 45), _target("nobody")
{
	std::srand((unsigned)time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm):
	AForm(robotomyRequestForm.getName(), robotomyRequestForm.getSignGrade(), robotomyRequestForm.getExecGrade()), _target(robotomyRequestForm.getTarget())
{
	std::srand((unsigned)time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand((unsigned)time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

const std::string&	RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

void	RobotomyRequestForm::realExecute(void) const
{
	std::rand();
	if (std::rand() % 2)
		std::cout << "RATATATATATATATATATATATA... " << this->_target << " has been succesfully robotomized" << std::endl;
	else
		std::cout << "Robotomy has failed" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& robotomyRequestForm)
{
	if (this != &robotomyRequestForm)
		std::cout << "Assignment operation is impossible: const values of base class cannot be overwritten" << std::endl;
	return *this;
}
