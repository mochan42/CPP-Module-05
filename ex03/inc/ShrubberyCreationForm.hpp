/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:37:45 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 19:09:04 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H_HPP
#define SHRUBBERYCREATIONFORM_H_HPP
#include <iostream>
#include <fstream> // header file for file I/O
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat; // to avoid error unknown type name 'Bureaucrat' for the member function beSigned

class	ShrubberyCreationForm : public AForm
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		ShrubberyCreationForm(); // Default constructor
		ShrubberyCreationForm(std::string const target);
		ShrubberyCreationForm(const ShrubberyCreationForm& src); // Default copy constructor
		~ShrubberyCreationForm(); // Destructor

		// OVERLOAD OPERATOR
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& src);

		// GETTERS - SETTERS
		std::string	getTarget(void) const;

		// MEMBER FUNCTIONS
		void		beSigned(Bureaucrat& bureaucrat);
		bool		execute(Bureaucrat const & obj) const;

	private:
		std::string	_target;
};

#endif