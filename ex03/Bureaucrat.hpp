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

# include "AForm.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class	AForm;

class	Bureaucrat
{
	private:
		std::string	_name;
		int			_grade;

		Bureaucrat(void);
	public:
		Bureaucrat(const Bureaucrat& bureaucrat);
		Bureaucrat(const std::string& name, const int& grade);
		~Bureaucrat(void);

		const std::string&	getName(void) const;
		const int&			getGrade(void) const;

		void	incrementGrade(void);
		void	decrementGrade(void);

		void	signForm(AForm& form) const;
		void	executeForm(AForm const& form) const;

		Bureaucrat&	operator=(const Bureaucrat& bureaucrat);

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
