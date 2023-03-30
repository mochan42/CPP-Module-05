/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:49:27 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 19:09:54 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.h"

//======== CONSTRUCTORS =========================================================================

RobotomyRequestForm::RobotomyRequestForm() :
	AForm(), _target("Default target")
{
	std::cout << BLU << "Default constructor called from RobotomyRequestForm" << D << "\n";
}

// Initialization of the derived class is made with the corresponding constructor of the immediate base class
RobotomyRequestForm::RobotomyRequestForm(std::string const target)
	: AForm("Random RobotomyRequestForm Name", false, 72, 45), _target(target)
{
	std::cout << BLU << "Initialized constructor called from RobotomyRequestForm" << D << "\n";
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << BLU << "Copy constructor called from RobotomyRequestForm" << D << "\n";
	*this = src;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
	std::cout << BLU << "Copy assignment operator called from RobotomyRequestForm" << D << "\n";
	this->_target =src.getTarget();
	return (*this);
}


//======== DESTRUCTOR ===========================================================================
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << CY << "Destructor called from RobotomyRequestForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}


//======== MEMBER FUNCTIONS =====================================================================
void		RobotomyRequestForm::beSigned(Bureaucrat& bureaucrat)
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
		std::cout << GREEN << "RobotomyRequestForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "RobotomyRequestForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}

bool		RobotomyRequestForm::execute(Bureaucrat const & obj) const
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
		std::time_t now = std::time(NULL);
		
		// If the seconds are odd, Robotomy is sucessfull
		if (now % 2 == 1)
		{
			std::cout << GREEN << "Bureaucrat " << BKLIGRN << obj.getName() << GREEN << " informs that " << getTarget() << " has been robotomized successfully" << D << "\n";
			formIsExecuted = true;
		}
		else
			std::cout << RED << "Robotomy failed" << D << "\n";
		return (formIsExecuted);
	}
	else
	{
		std::cout << RED << "RobotomyRequestForm NOT executed" << D << "\n";
		return (formIsExecuted);
	}
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const RobotomyRequestForm& RobotomyRequestForm )
{
	outputStream << BKLIGRN << RobotomyRequestForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << RobotomyRequestForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << RobotomyRequestForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << RobotomyRequestForm.getGradeToExec() << D << "\n";
	return (outputStream);
}