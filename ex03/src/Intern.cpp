/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:23:01 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 23:31:54 by mochan           ###   ########.fr       */
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
AForm*	Intern::makeForm( std::string form, std::string target )
{
	AForm*	tmp = NULL;
	std::string	form_list[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int i = 1;

	while (i < 3)
	{
		if (form == form_list[i - 1])
			break;
		i++;
	}
	switch(i)
	{
		case 1:
			tmp = new ShrubberyCreationForm(target);
			break;
		case 2:
			tmp = new RobotomyRequestForm(target);
			break;
		case 3:
			tmp = new PresidentialPardonForm(target);
			break;
		default:
			std::cout << RED << "/!\\ WRONG FORM /!\\" << D << "\n";
			break;
	}
	std::cout << "Intern creates " << form << "\n";
	return (tmp);
}

