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

typedef struct s_forms
{
	std::string	name;
	AForm*		form;
}	t_forms;

class	Intern
{
	public:
		Intern(void);
		~Intern(void);

		AForm*	makeForm(std::string formName, std::string target);
};

#endif
