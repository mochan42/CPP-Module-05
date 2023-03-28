/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:40:26 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 22:44:37 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"

//======== CONSTRUCTORS =========================================================================

ShrubberyCreationForm::ShrubberyCreationForm()
	: _name ("Random ShrubberyCreationForm Name"), _isSigned (0), _gradeToSign (145), _gradeToExec (137)
{
	std::cout << BLU << "Default constructor called from ShrubberyCreationForm" << D << "\n";
}

// e.what() is a member function of the std::exception class.
// It returns a const char* that represents the explanatory string associated with the exception.
// This string can be set when the exception is thrown, and it provides inShrubberyCreationFormation about the exception.
ShrubberyCreationForm::ShrubberyCreationForm(const std::string setName, bool setIsSigned, const int 145, const int 137)
	: _name(setName), _isSigned (setIsSigned), _gradeToSign (145), _gradeToExec (137)
{
	std::cout << BLU << "Initialized constructor called from ShrubberyCreationForm" << D << "\n";
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

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << BLU << "Copy constructor called from ShrubberyCreationForm" << D << "\n";
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << BLU << "Copy assignment operator called from ShrubberyCreationForm" << D << "\n";
	this->_name =src._name;
	this->_isSigned =src._isSigned;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CY << "Destructor called from ShrubberyCreationForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string		ShrubberyCreationForm::getName( void ) const
{
	return (this->_name);
}

bool			ShrubberyCreationForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int				ShrubberyCreationForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int				ShrubberyCreationForm::getGradeToExec( void ) const
{
	return (this->_gradeToExec);
}

//======== MEMBER FUNCTIONS =====================================================================
void		ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
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
		std::cout << GREEN << "ShrubberyCreationForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "ShrubberyCreationForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const ShrubberyCreationForm& ShrubberyCreationForm )
{
	outputStream << BKLIGRN << ShrubberyCreationForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << ShrubberyCreationForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << ShrubberyCreationForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << ShrubberyCreationForm.getGradeToExec() << D << "\n";
	return (outputStream);
}