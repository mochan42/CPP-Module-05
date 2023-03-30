/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 11:58:04 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"
#include "Intern.h"

int main()
{
	std::cout << PU << "\n---------- Intern 1: ShrubberyCreationForm ----------" << D << "\n";
	Bureaucrat	Tom("Tom", 2);
	Intern	intern_1;
	AForm	*form_1;

	form_1 = intern_1.makeForm("ShrubberyCreationForm", "palm_tree");
	form_1->beSigned(Tom);
	Tom.signForm(*form_1);
	Tom.executeForm(*form_1);


	std::cout << PU << "\n---------- Intern 2: RobotomyRequestForm ----------" << D << "\n";
	Bureaucrat	Jerry("Jerry", 2);
	Intern	intern_2;
	AForm	*form_2;

	form_2 = intern_2.makeForm("RobotomyRequestForm", "palm_tree");
	form_2->beSigned(Jerry);
	Jerry.signForm(*form_2);
	Jerry.executeForm(*form_2);

	std::cout << PU << "\n---------- Intern 3: PresidentialPardonForm ----------" << D << "\n";
	Bureaucrat	Carl("Carl", 2);
	Intern	intern_3;
	AForm	*form_3;

	form_3 = intern_3.makeForm("PresidentialPardonForm", "Ford Prefect");
	form_3->beSigned(Carl);
	Carl.signForm(*form_3);
	Carl.executeForm(*form_3);

	delete form_1;
	delete form_2;
	delete form_3;
	return 0;
}