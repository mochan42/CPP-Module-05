/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 18:21:16 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "AForm.h"
#include "ShrubberyCreationForm.h"

int main()
{
	Bureaucrat				Louis("Louis", 80);
	ShrubberyCreationForm	ShruberryForm_1("fly-request");

	std::cout << Louis;
	std::cout << ShruberryForm_1;
	std::cout << "Target of " << ShruberryForm_1.getName() << " is " << ShruberryForm_1.getTarget() << "\n";

	return 0;
}