/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:56:49 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 22:07:45 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.h"

//======== CONSTRUCTORS =========================================================================

PresidentialPardonForm::PresidentialPardonForm() :
	AForm(), _target("Default target")
{
	std::cout << BLU << "Default constructor called from PresidentialPardonForm" << D << "\n";
}

// Initialization of the derived class is made with the corresponding constructor of the immediate base class
PresidentialPardonForm::PresidentialPardonForm(std::string const target)
	: AForm("Random PresidentialPardonForm Name", false, 25, 5), _target(target)
{
	std::cout << BLU << "Initialized constructor called from PresidentialPardonForm" << D << "\n";
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << BLU << "Copy constructor called from PresidentialPardonForm" << D << "\n";
	*this = src;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
	std::cout << BLU << "Copy assignment operator called from PresidentialPardonForm" << D << "\n";
	this->_target =src.getTarget();
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << CY << "Destructor called from PresidentialPardonForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}


//======== MEMBER FUNCTIONS =====================================================================
void		PresidentialPardonForm::beSigned(Bureaucrat bureaucrat)
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
		setIsSigned(true);
		std::cout << GREEN << "PresidentialPardonForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "PresidentialPardonForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}

bool		PresidentialPardonForm::execute(Bureaucrat const & obj) const
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
		formIsExecuted = true;
		std::cout << GREEN << "Bureaucrat " << BKLIGRN << obj.getName() << GREEN << " informs that " << getTarget() << " has been pardoned by Zaphod Beeblebrox" << D << "\n";
		return (formIsExecuted);
	}
	else
	{
		std::cout << RED << "PresidentialPardonForm NOT executed" << D << "\n";
		return (formIsExecuted);
	}
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const PresidentialPardonForm& PresidentialPardonForm )
{
	outputStream << BKLIGRN << PresidentialPardonForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << PresidentialPardonForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << PresidentialPardonForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << PresidentialPardonForm.getGradeToExec() << D << "\n";
	return (outputStream);
}