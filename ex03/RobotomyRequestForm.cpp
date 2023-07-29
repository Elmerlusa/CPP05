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

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand((unsigned)time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

void	RobotomyRequestForm::realExecute(void) const
{
	std::cout << "RATATATATATATATATATATATA... ";
	if (std::rand() % 2)
		std::cout << this->_target << " has been succesfully robotomized" << std::endl;
	else
		std::cout << "Robotomy has failed" << std::endl;
}
