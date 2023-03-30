/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 20:23:05 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 12:12:45 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.h"

//======== CONSTRUCTORS =========================================================================

Form::Form()
	: _name ("Random Form Name"), _isSigned (0), _gradeToSign (1), _gradeToExec (1)
{
	std::cout << BLU << "Default constructor called from Form" << D << "\n";
}

// e.what() is a member function of the std::exception class.
// It returns a const char* that represents the explanatory string associated with the exception.
// This string can be set when the exception is thrown, and it provides information about the exception.
Form::Form(const std::string setName, bool setIsSigned, const int setGradeToSign, const int setGradeToExec)
	: _name(setName), _isSigned (setIsSigned), _gradeToSign (setGradeToSign), _gradeToExec (setGradeToExec)
{
	std::cout << BLU << "Initialized constructor called from Form" << D << "\n";
	try
	{
		if ( setGradeToSign < 1 || setGradeToExec < 1 )
			throw GradeTooHighException();
		else if ( setGradeToSign > 150 || setGradeToExec > 150 )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
}

Form::Form(const Form& src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << BLU << "Copy constructor called from Form" << D << "\n";
}

Form&	Form::operator=(const Form& src)
{
	std::cout << BLU << "Copy assignment operator called from Form" << D << "\n";
	this->_isSigned =src._isSigned;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
Form::~Form()
{
	std::cout << CY << "Destructor called from Form" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
const std::string		Form::getName( void ) const
{
	return (this->_name);
}

bool			Form::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int				Form::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int				Form::getGradeToExec( void ) const
{
	return (this->_gradeToExec);
}

//======== MEMBER FUNCTIONS =====================================================================
void		Form::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if ( getGradeToSign() > 150 )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (bureaucrat.getGrade() <= getGradeToSign() )
	{
		_isSigned = 1;
		std::cout << GREEN << "Form " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "Form " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const Form& Form )
{
	outputStream << BKLIGRN << Form.getName() << YELL << ", with boolean isSigned = " << LIGRN << Form.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << Form.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << Form.getGradeToExec() << D << "\n";
	return (outputStream);
}