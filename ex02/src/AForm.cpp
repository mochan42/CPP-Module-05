/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:29:09 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 19:05:52 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.h"

//======== CONSTRUCTORS =========================================================================

AForm::AForm()
	: _name ("Random AForm Name"), _isSigned (false), _gradeToSign (1), _gradeToExec (1)
{
	std::cout << BLU << "Default constructor called from AForm" << D << "\n";
}

// e.what() is a member function of the std::exception class.
// It returns a const char* that represents the explanatory string associated with the exception.
// This string can be set when the exception is thrown, and it provides inAFormation about the exception.
AForm::AForm(const std::string setName, bool setIsSigned, const int setGradeToSign, const int setGradeToExec)
	: _name(setName), _isSigned(setIsSigned), _gradeToSign(setGradeToSign), _gradeToExec(setGradeToExec)
{
	std::cout << BLU << "Initialized constructor called from AForm" << D << "\n";
	try
	{
		if ( getGradeToSign() < 1 || getGradeToExec() < 1 )
			throw GradeTooHighException();
		else if ( getGradeToSign() > 150 || getGradeToExec() > 150 )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
}

AForm::AForm(const AForm& src)
	: _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
	std::cout << BLU << "Copy constructor called from AForm" << D << "\n";
}

AForm&	AForm::operator=(const AForm& src)
{
	std::cout << BLU << "Copy assignment operator called from AForm" << D << "\n";
	this->_isSigned =src._isSigned;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
AForm::~AForm()
{
	std::cout << CY << "Destructor called from AForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
const std::string		AForm::getName( void ) const
{
	return (this->_name);
}

bool			AForm::getIsSigned( void ) const
{
	return (this->_isSigned);
}

int				AForm::getGradeToSign( void ) const
{
	return (this->_gradeToSign);
}

int				AForm::getGradeToExec( void ) const
{
	return (this->_gradeToExec);
}

void			AForm::setIsSigned( bool setBool )
{
	_isSigned = setBool;
}


//======== MEMBER FUNCTIONS =====================================================================
void		AForm::beSigned(Bureaucrat& bureaucrat)
{
	try
	{
		if ( bureaucrat.getGrade() > getGradeToSign() )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (bureaucrat.getGrade() <= getGradeToSign() )
	{
		this->_isSigned = true;
		std::cout << GREEN << "AForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "AForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}

bool		AForm::execute(Bureaucrat const & obj) const
{
	bool	formIsExecuted = false;

	try
	{
		if (getIsSigned() == false)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (getIsSigned() == true && obj.getGrade() <= getGradeToExec() )
	{
		std::cout << GREEN << "Bureaucrat " << BKLIGRN << obj.getName() << GREEN << " authorized to execute form" << D << "\n";
		formIsExecuted = true;
		return (formIsExecuted);
	}
	else
	{
		std::cout << RED << "Bureaucrat " << BKLIGRN << obj.getName() << RED << " NOT authorized to execute form" << D << "\n";
		return (formIsExecuted);
	}
}

//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const AForm& AForm )
{
	outputStream << BKLIGRN << AForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << AForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << AForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << AForm.getGradeToExec() << D << "\n";
	return (outputStream);
}