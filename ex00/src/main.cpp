/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:28:53 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 14:18:47 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.h"

int main()
{
	Bureaucrat	Louis;

	std::cout << "Bureaucrat " << Louis.getName() << " has a grade : " << Louis.getGrade() << "\n";
	return 0;
}