/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:37:45 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 22:43:53 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H_HPP
#define SHRUBBERYCREATIONFORM_H_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat; // to avoid error unknown type name 'Bureaucrat' for the member function beSigned

class	ShrubberyCreationForm : public AForm
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		ShrubberyCreationForm(); // Default constructor
		ShrubberyCreationForm(const std::string setName, bool setIsSigned, const int setGradeToSign, const int setGradeToExec);
		ShrubberyCreationForm(const Form& other); // Default copy constructor
		~ShrubberyCreationForm(); // Destructor

		// OVERLOAD OPERATOR
		ShrubberyCreationForm& operator=(const Form& src);

};

#endif