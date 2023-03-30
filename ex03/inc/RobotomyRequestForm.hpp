/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 20:54:54 by mochan            #+#    #+#             */
/*   Updated: 2023/03/30 19:09:30 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat; // to avoid error unknown type name 'Bureaucrat' for the member function beSigned

class	RobotomyRequestForm : public AForm
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		RobotomyRequestForm(); // Default constructor
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(const RobotomyRequestForm& src); // Default copy constructor
		~RobotomyRequestForm(); // Destructor

		// OVERLOAD OPERATOR
		RobotomyRequestForm& operator=(const RobotomyRequestForm& src);

		// GETTERS - SETTERS
		std::string	getTarget(void) const;

		// MEMBER FUNCTIONS
		void		beSigned(Bureaucrat& bureaucrat);
		bool		execute(Bureaucrat const & obj) const;

	private:
		std::string	_target;
};

#endif
