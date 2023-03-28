/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:24:28 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 20:59:01 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP
#include <iostream>

class	Form
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Form(); // Default constructor
		Form(const std::string setName, bool setIsSigned, const int setGradeToSign, const int setGradeToExec);
		Form(const Form& other); // Default copy constructor
		~Form(); // Destructor

		// OVERLOAD OPERATOR
		Form& operator=(const Form& src);

		// GETTERS - SETTERS
		std::string	getName(void) const;
		bool		getIsSigned(void) const;
		int			getGradeToSign(void) const;
		int			getGradeToExec(void) const;

		// MEMBER FUNCTIONS
		// void	incrementGrade( void );
		// void	decrementGrade( void );

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

std::ostream& operator<<( std::ostream& outputStream, const Form& Form );

#endif