/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:02 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 11:14:14 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "AForm.hpp"

class	AForm;

class	Bureaucrat
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Bureaucrat(); // Default constructor
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat& other); // Default copy constructor
		~Bureaucrat(); // Destructor

		// OVERLOAD OPERATOR
		Bureaucrat& operator=(const Bureaucrat& src);

		// GETTERS - SETTERS
		std::string	getName(void) const;
		int			getGrade(void) const;

		// MEMBER FUNCTIONS
		void	incrementGrade( void );
		void	decrementGrade( void );
		void	signForm( AForm& form );
		void	executeForm( AForm const & form );

		// An exception should be thrown as an object of a specific type (like a class)
		// that derives from std::exception or a subclass of std::exception.
		// We need to define exception classes for GradeTooHighException and GradeTooLowException
		// that inherit from std::exception or a subclass of std::exception.
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high, maximum grade is 1.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low, minimum grade is 150.");
				}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<( std::ostream& outputStream, const Bureaucrat& bureaucrat );

#endif