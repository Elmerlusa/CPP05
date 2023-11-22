/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:41:14 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 14:41:14 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <cstdlib>

# include "AForm.hpp"

class	RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

		RobotomyRequestForm(void);
	public:
		RobotomyRequestForm(const RobotomyRequestForm& robotomyRequestForm);
		RobotomyRequestForm(const std::string& target);
		~RobotomyRequestForm(void);

		const std::string&	getTarget(void) const;
		
		void	realExecute(void) const;
		
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& robotomyRequestForm);
};

#endif
