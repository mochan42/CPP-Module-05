/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 21:46:32 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "unistd.h"

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

	std::cout << BLA << "\n---------- ShrubberyCreationForm NOT Signed and NOT executed ----------" << D << "\n";
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

	std::cout << PU << "\n---------- RobotomyRequestForm Signed and Executed ----------" << D << "\n";
	std::cout << Michael;
	std::cout << Robotomy_1;
	Robotomy_1.beSigned(Michael);
	Michael.signForm(Robotomy_1);
	Michael.executeForm(Robotomy_1);

	std::cout << PU << "\n---------- RobotomyRequestForm Signed and NOT Executed ----------" << D << "\n";
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

	return 0;
}