/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:00:23 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 22:01:02 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat; // to avoid error unknown type name 'Bureaucrat' for the member function beSigned

class	PresidentialPardonForm : public AForm
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		PresidentialPardonForm(); // Default constructor
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(const PresidentialPardonForm& src); // Default copy constructor
		~PresidentialPardonForm(); // Destructor

		// OVERLOAD OPERATOR
		PresidentialPardonForm& operator=(const PresidentialPardonForm& src);

		// GETTERS - SETTERS
		std::string	getTarget(void) const;

		// MEMBER FUNCTIONS
		void		beSigned(Bureaucrat bureaucrat);
		bool		execute(Bureaucrat const & obj) const;

	private:
		std::string	_target;
};

#endif

