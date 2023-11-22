/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:35:02 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/29 14:35:02 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class	PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

		PresidentialPardonForm(void);
	public:
		PresidentialPardonForm(const PresidentialPardonForm& presidentialPardonForm);
		PresidentialPardonForm(const std::string& target);
		~PresidentialPardonForm(void);

		const std::string&	getTarget(void) const;

		void	realExecute(void) const;

		PresidentialPardonForm&	operator=(const PresidentialPardonForm& presidentialPardonForm);
};

#endif
