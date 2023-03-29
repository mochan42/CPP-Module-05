/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:40:26 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 18:20:11 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"

//======== CONSTRUCTORS =========================================================================

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(), _target("Default target")
{
	std::cout << BLU << "Default constructor called from ShrubberyCreationForm" << D << "\n";
}

// Initialization of the derived class is made with the corresponding constructor of the immediate base class
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: AForm("Random ShrubberyCreationForm Name", false, 145, 137), _target(target)
{
	std::cout << BLU << "Initialized constructor called from ShrubberyCreationForm" << D << "\n";
	this->_target = (_target + "_shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << BLU << "Copy constructor called from ShrubberyCreationForm" << D << "\n";
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << BLU << "Copy assignment operator called from ShrubberyCreationForm" << D << "\n";
	this->_target =src.getTarget();
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CY << "Destructor called from ShrubberyCreationForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
// std::string		ShrubberyCreationForm::getName( void ) const
// {
// 	return (this->_name);
// }

// bool			ShrubberyCreationForm::getIsSigned( void ) const
// {
// 	return (this->_isSigned);
// }

// int				ShrubberyCreationForm::getGradeToSign( void ) const
// {
// 	return (this->_gradeToSign);
// }

// int				ShrubberyCreationForm::getGradeToExec( void ) const
// {
// 	return (this->_gradeToExec);
// }

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}


//======== MEMBER FUNCTIONS =====================================================================
void		ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if ( getGradeToSign() > 145 )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (bureaucrat.getGrade() <= getGradeToSign() )
	{
		setIsSigned(true);
		std::cout << GREEN << "ShrubberyCreationForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "ShrubberyCreationForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}

void		ShrubberyCreationForm::execute(Bureaucrat const & obj) const
{
	(void) obj;
	std::cout << YELL << "ShrubberyCreationForm " << BKLIGRN << getName() << YELL <<  " executes Shrubbery action " << D << "\n";
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const ShrubberyCreationForm& ShrubberyCreationForm )
{
	outputStream << BKLIGRN << ShrubberyCreationForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << ShrubberyCreationForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << ShrubberyCreationForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << ShrubberyCreationForm.getGradeToExec() << D << "\n";
	return (outputStream);
}