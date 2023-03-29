/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 20:21:37 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"

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

	return 0;
}