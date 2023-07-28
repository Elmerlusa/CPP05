/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:28:23 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/13 16:28:23 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <stdexcept>

#include "Form.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Form;

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;
	public:
		Bureaucrat(std::string name, int grade);
		~Bureaucrat(void);

		std::string	getName(void) const;
		int			getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(Form& form) const;

		class	GradeTooHighException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& ostr, const Bureaucrat& bureaucrat);

#endif
