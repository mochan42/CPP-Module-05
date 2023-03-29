/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 22:13:06 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"


int main()
{
	Bureaucrat				Louis("Louis", 80);
	Bureaucrat				Pierre("Pierre", 138);
	Bureaucrat				Gaston("Gaston", 146);
	ShrubberyCreationForm	ShruberryForm_1("draw_tree_1");
	ShrubberyCreationForm	ShruberryForm_2("draw_tree_2");
	ShrubberyCreationForm	ShruberryForm_3("draw_tree_3");

	std::cout << PU << "\n---------- ShrubberyCreationForm Signed and Executed ----------" << D << "\n";
	std::cout << Louis;
	std::cout << ShruberryForm_1;
	// std::cout << "Target of " << ShruberryForm_1.getName() << " is " << ShruberryForm_1.getTarget() << "\n";
	ShruberryForm_1.beSigned(Louis);
	Louis.signForm(ShruberryForm_1);
	Louis.executeForm(ShruberryForm_1);

	std::cout << PU << "\n---------- ShrubberyCreationForm Signed but NOT executed ----------" << D << "\n";
	std::cout << Pierre;
	std::cout << ShruberryForm_2;
	// std::cout << "Target of " << ShruberryForm_2.getName() << " is " << ShruberryForm_2.getTarget() << "\n";
	ShruberryForm_2.beSigned(Pierre);
	Pierre.signForm(ShruberryForm_2);
	Pierre.executeForm(ShruberryForm_2);

	std::cout << PU << "\n---------- ShrubberyCreationForm NOT Signed and NOT executed ----------" << D << "\n";
	std::cout << Gaston;
	std::cout << ShruberryForm_3;
	// std::cout << "Target of " << ShruberryForm_3.getName() << " is " << ShruberryForm_3.getTarget() << "\n";
	ShruberryForm_3.beSigned(Gaston);
	Gaston.signForm(ShruberryForm_3);
	Gaston.executeForm(ShruberryForm_3);

	std::cout << "\n\n\n";
	Bureaucrat				Michael("Michael", 40);
	Bureaucrat				Peter("Peter", 46);
	Bureaucrat				Dieter("Dieter", 73);
	RobotomyRequestForm		Robotomy_1("Han");
	RobotomyRequestForm		Robotomy_2("Luke");
	RobotomyRequestForm		Robotomy_3("Leia");

	std::cout << WH << "\n---------- RobotomyRequestForm Signed and Executed ----------" << D << "\n";
	std::cout << Michael;
	std::cout << Robotomy_1;
	Robotomy_1.beSigned(Michael);
	Michael.signForm(Robotomy_1);
	Michael.executeForm(Robotomy_1);

	std::cout << WH << "\n---------- RobotomyRequestForm Signed and NOT Executed ----------" << D << "\n";
	std::cout << Peter;
	std::cout << Robotomy_2;
	Robotomy_2.beSigned(Peter);
	Peter.signForm(Robotomy_2);
	Peter.executeForm(Robotomy_2);

	std::cout << WH << "\n---------- RobotomyRequestForm NOT Signed and NOT Executed ----------" << D << "\n";
	std::cout << Dieter;
	std::cout << Robotomy_3;
	Robotomy_3.beSigned(Dieter);
	Dieter.signForm(Robotomy_3);
	Dieter.executeForm(Robotomy_3);
	
	std::cout << "\n\n\n";
	Bureaucrat					Alfonso("Alsonso", 2);
	Bureaucrat					Miguel("Miguel", 6);
	Bureaucrat					Rodrigo("Rodrigo", 26);
	PresidentialPardonForm		PresidentialPardon_1("Mike");
	PresidentialPardonForm		PresidentialPardon_2("Alex");
	PresidentialPardonForm		PresidentialPardon_3("John");
	
	std::cout << BLA << "\n---------- PresidentialPardonForm Signed and Executed ----------" << D << "\n";
	std::cout << Alfonso;
	std::cout << PresidentialPardon_1;
	PresidentialPardon_1.beSigned(Alfonso);
	Alfonso.signForm(PresidentialPardon_1);
	Alfonso.executeForm(PresidentialPardon_1);

	std::cout << BLA << "\n---------- PresidentialPardonForm Signed and NOT Executed ----------" << D << "\n";
	std::cout << Miguel;
	std::cout << PresidentialPardon_2;
	PresidentialPardon_2.beSigned(Miguel);
	Miguel.signForm(PresidentialPardon_2);
	Miguel.executeForm(PresidentialPardon_2);

	std::cout << BLA << "\n---------- PresidentialPardonForm NOT Signed and NOT Executed ----------" << D << "\n";
	std::cout << Rodrigo;
	std::cout << PresidentialPardon_3;
	PresidentialPardon_3.beSigned(Rodrigo);
	Rodrigo.signForm(PresidentialPardon_3);
	Rodrigo.executeForm(PresidentialPardon_3);

	return 0;
}