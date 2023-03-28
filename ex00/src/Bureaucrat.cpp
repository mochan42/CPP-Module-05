/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 21:08:45 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

//======== CONSTRUCTORS =========================================================================

Bureaucrat::Bureaucrat() : _name ("Random Bureaucrat Name")
{
	std::cout << BLU << "Default constructor called from Bureaucrat" << D << "\n";
	this->_grade = 75;
}

// e.what() is a member function of the std::exception class.
// It returns a const char* that represents the explanatory string associated with the exception.
// This string can be set when the exception is thrown, and it provides information about the exception.
Bureaucrat::Bureaucrat(const std::string setName, int setGrade) : _name(setName)
{
	std::cout << BLU << "Initialized constructor called from Bureaucrat" << D << "\n";
	try
	{
		if ( setGrade < 1)
			throw GradeTooHighException();
		else if ( setGrade > 150 )
			throw GradeTooLowException();
		else
			_grade = setGrade;
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
		std::cout << RED << "Grade of " << getName() << " reseted to lowest value 150." << D << "\n";
		_grade = 150;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	std::cout << BLU << "Copy constructor called from Bureaucrat" << D << "\n";
	*this = src;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& src)
{
	std::cout << BLU << "Copy assignment operator called from Bureaucrat" << D << "\n";
	this->_grade = src._grade;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
Bureaucrat::~Bureaucrat()
{
	std::cout << CY << "Destructor called from Bureaucrat" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string		Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

//======== MEMBER FUNCTIONS =====================================================================
void	Bureaucrat::incrementGrade( void )
{
	try
	{
		if ( _grade < 2)
			throw GradeTooHighException();
		else
		{
			_grade--;
			std::cout << GREEN << "Grade of " << BKLIGRN << getName() << GREEN << " is incremented." << D << "\n";
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
		std::cout << RED << "Grade of " << getName() << " cannot be incremented." << D << "\n";
	}
}

void	Bureaucrat::decrementGrade( void )
{
	try
	{
		if ( _grade > 149)
			throw GradeTooLowException();
		else
		{
			_grade++;
			std::cout << PU << "Grade of " << BKLIGRN << getName() << PU << " is decremented." << D << "\n";
		}
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
		std::cout << RED << "Grade of " << getName() << " cannot be decremented." << D << "\n";
	}
}


//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const Bureaucrat& bureaucrat )
{
	outputStream << BKLIGRN << bureaucrat.getName() << YELL << ", bureaucrat grade " << LIGRN << bureaucrat.getGrade() << D;
	return (outputStream);
}