/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 13:10:00 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/28 13:10:00 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class	ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

		ShrubberyCreationForm(void);
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm& shrubberyCreationForm);
		ShrubberyCreationForm(const std::string& target);
		~ShrubberyCreationForm(void);

		const std::string&	getTarget(void) const;

		void	realExecute(void) const;

		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& shrubberyCreationForm);
};

#endif
