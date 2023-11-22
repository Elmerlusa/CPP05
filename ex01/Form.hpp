/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javmarti <javmarti@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 17:59:58 by javmarti          #+#    #+#             */
/*   Updated: 2023/07/24 17:59:58 by javmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		Form(void);
	public:
		Form(const Form& form);
		Form(const std::string& name, const int& signGrade, const int& execGrade);
		~Form(void);

		const std::string&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getSignGrade(void) const;
		const int&			getExecGrade(void) const;

		void	beSigned(const Bureaucrat& bureaucrat);

		Form&	operator=(const Form& form);

		class	GradeTooHighException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& ostr, const Form& form);

#endif
