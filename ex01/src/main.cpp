/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 20:56:58 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	Bureaucrat	Louis("Louis", 97);
	Form		flyRequest("Fly-Request", 0, 100, 50);

	// Bureaucrat	Jean("Jean", 0);
	// Bureaucrat	Gaston("Gaston", 151);
	// Bureaucrat	Sarah("Sarah", 1);
	// Bureaucrat	Leon("Leon", 150);

	// std::cout << "\n--------- Initialization caught by Exception Grade too high ---------\n";
	// std::cout << Jean << "\n";

	// std::cout << "\n--------- Initialization caught by Exception Grade too low ---------\n";
	// std::cout << Gaston << "\n";


	// std::cout << "\n--------- Increment caught by Exception Grade too low ---------\n";
	// std::cout << Sarah << "\n";
	// Sarah.incrementGrade();
	// std::cout << Sarah << "\n";

	// std::cout << "\n--------- Decrement caught by Exception Grade too low ---------\n";
	// std::cout << Leon << "\n";
	// Leon.decrementGrade();
	// std::cout << Leon << "\n";

	std::cout << "\n--------- Normal Bureaucrat evolution ---------\n";
	std::cout << Louis << "\n";
	std::cout << flyRequest << "\n";
	// Louis.incrementGrade();
	// Louis.incrementGrade();
	// std::cout << Louis << "\n";
	// Louis.decrementGrade();
	// std::cout << Louis << "\n\n";
	

	return 0;
}