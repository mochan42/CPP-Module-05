/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 18:27:55 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"
#include "Form.h"

int main()
{
	Bureaucrat	Louis("Louis", 80);
	Bureaucrat	Rene("Rene", 120);
	Form		flyRequest("Fly-Request", 0, 100, 50);
	Form		sailingRequest("sailing-Request", 0, 100, 50);

	std::cout << PU << "\n--------- Forms with out of range grades ---------" << D << "\n";
	Form		fishingRequest("fishing-Request", 0, 0, 50);
	Form		huntingRequest("hunting-Request", 0, 151, 50);
	Form		skatingRequest("skating-Request", 0, 50, 0);
	Form		holidayRequest("holiday-Request", 0, 50, 151);

	std::cout << PU << "\n--------- Form CAN be signed ---------" << D << "\n";
	std::cout << Louis;
	std::cout << flyRequest;
	flyRequest.beSigned(Louis);
	Louis.signForm(flyRequest);
	std::cout << flyRequest;
	
	std::cout << PU << "\n--------- Form CANNOT be signed ---------" << D << "\n";
	std::cout << Rene;
	std::cout << sailingRequest;
	sailingRequest.beSigned(Rene);
	std::cout << sailingRequest;
	Rene.signForm(sailingRequest);
	std::cout << "\n";

	return 0;
}