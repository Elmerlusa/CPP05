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
	public:
		Intern(void);
		~Intern(void);

		AForm*	makeForm(std::string formName, std::string target) const;
	private:
		typedef struct s_form_map
		{
			std::string	name;
			AForm*		(*f)(std::string);
		}	t_form_map;
		
		// AForm*	createShrubberyForm(std::string target);
		// AForm*	createRobotomyForm(std::string target);
		// AForm*	createPresidentialForm(std::string target);
};

#endif
