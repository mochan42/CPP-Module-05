/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:24:59 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 14:16:21 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

//======== CONSTRUCTORS =========================================================================

Bureaucrat::Bureaucrat() : _name ("Random Bureaucrat Name")
{
	std::cout << BLU << "Default constructor called from Bureaucrat" << D << "\n";
	this->_grade = 97;
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

// void	Bureaucrat::setName(const std::string setName) const
// {
// 	_name = setName;
// }

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

// void	Bureaucrat::setGrade(int setGrade) const
// {
// 	_grade = setGrade;
// }

//======== MEMBER FUNCTIONS =====================================================================
void	Bureaucrat::GradeTooHighException( void )
{
	std::cout << "Grade is too high, maximum grade is 1.\n";
}

void	Bureaucrat::GradeTooLowException( void )
{
	std::cout << "Grade is too low, minimum grade is 150.\n";
}

void	Bureaucrat::incrementGrade( void )
{
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	_grade++;
}