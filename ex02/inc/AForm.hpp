/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:29:22 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 17:56:37 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat; // to avoid error unknown type name 'Bureaucrat' for the member function beSigned

class	AForm
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		AForm(); // Default constructor
		AForm(const std::string setName, bool setIsSigned, const int setGradeToSign, const int setGradeToExec);
		AForm(const AForm& other); // Default copy constructor
		~AForm(); // Destructor

		// OVERLOAD OPERATOR
		AForm& operator=(const AForm& src);

		// GETTERS - SETTERS
		std::string	getName( void ) const;
		bool		getIsSigned( void ) const;
		int			getGradeToSign( void ) const;
		int			getGradeToExec( void ) const;
		void		setIsSigned( bool setBool );

		// MEMBER FUNCTIONS
		virtual void		beSigned(Bureaucrat bureaucrat) = 0;
		virtual void		execute(Bureaucrat const & obj) const = 0;

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
		std::string		_name;
		bool			_isSigned;
		const int		_gradeToSign;
		const int		_gradeToExec;
};

std::ostream& operator<<( std::ostream& outputStream, const AForm& Form );

#endif