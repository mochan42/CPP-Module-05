/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:23:01 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 23:04:39 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.h"

//======== CONSTRUCTORS =========================================================================

Intern::Intern()
{
	std::cout << BLU << "Default constructor called from Intern" << D << "\n";
}

Intern::Intern(const Intern& src)
{
	std::cout << BLU << "Copy constructor called from Intern" << D << "\n";
	*this = src;
}

Intern&	Intern::operator=(const Intern& src)
{
	std::cout << BLU << "Copy assignment operator called from Intern" << D << "\n";
	(void)src;
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
Intern::~Intern()
{
	std::cout << CY << "Destructor called from Intern" << D << "\n";
}


//======== MEMBER FUNCTIONS =====================================================================
void	Intern::makeForm( std::string form, std::string target )
{
	std::string	form_list[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 1;

	while (i < 3)
	{
		if (form == form_list[i - 1])
			break;
		i++;
	}
	std::cout << "i = " << i << "\n";
	switch(i)
	{
		case 1:
			{
				std::cout << "Intern creates ShrubberyCreationForm with " + target << "\n";
			}
			break;
		case 2:
			{
				std::cout << "Intern creates RobotomyRequestForm with " + target << "\n";
			}
			break;
		case 3:
			{
				std::cout << "Intern creates PresidentialPardonForm with " + target << "\n";
			}
			break;
		default:
			std::cout << RED << "/!\\ WRONG FORM /!\\" << D << "\n";
			break;
	}
}

