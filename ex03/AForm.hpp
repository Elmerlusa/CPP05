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

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <stdexcept>

# include "Bureaucrat.hpp"

# define MAX_GRADE 1
# define MIN_GRADE 150

class	Bureaucrat;

class	AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

		AForm(void);
	public:
		AForm(const AForm& form);
		AForm(const std::string& name, const int& signGrade, const int& execGrade);
		virtual ~AForm(void);

		const std::string&	getName(void) const;
		const bool&			getSigned(void) const;
		const int&			getSignGrade(void) const;
		const int&			getExecGrade(void) const;

		void			beSigned(const Bureaucrat& bureaucrat);
		void			execute(Bureaucrat const& executor) const;
		virtual void	realExecute(void) const = 0;

		AForm&	operator=(const AForm& form);

		class	FormNotSignedException: public std::exception
		{
			virtual const char* what(void) const throw();
		};

		class	GradeTooHighException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};

		class	GradeTooLowException: public std::exception
		{
			virtual const char*	what(void) const throw();
		};
};

std::ostream&	operator<<(std::ostream& ostr, const AForm& form);

#endif
