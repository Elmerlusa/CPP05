/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:36:45 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 14:36:45 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("DefaultName", 25, 5), _target("nobody")
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm):
	AForm(presidentialPardonForm.getName(), presidentialPardonForm.getSignGrade(), presidentialPardonForm.getExecGrade()), _target(presidentialPardonForm.getTarget())
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}

const std::string&	PresidentialPardonForm::getTarget(void) const
{
	return this->_target;
}

void	PresidentialPardonForm::realExecute(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& presidentialPardonForm)
{
	if (this != &presidentialPardonForm)
		std::cout << "Assignment operation is impossible: const values of base class cannot be overwritten" << std::endl;
	return *this;
}
