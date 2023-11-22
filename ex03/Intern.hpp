/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:21:37 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 15:21:37 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <iostream>

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class	Intern
{
	private:
		AForm*	createShrubberyForm(const std::string& target) const;
		AForm*	createRobotomyForm(const std::string& target) const;
		AForm*	createPresidentialForm(const std::string& target) const;
	public:
		Intern(void);
		Intern(const Intern& intern);
		~Intern(void);

		AForm*	makeForm(const std::string& formName, const std::string& target) const;

		Intern&	operator=(const Intern& intern);
};

#endif
