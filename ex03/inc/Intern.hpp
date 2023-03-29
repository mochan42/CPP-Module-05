/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:25:27 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 22:58:27 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>

class	Intern
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Intern(); // Default constructor
		Intern(const Intern& other); // Default copy constructor
		~Intern(); // Destructor
		
		// OVERLOAD OPERATOR
		Intern& operator=(const Intern& src);
		
		// MEMBER FUNCTIONS
		void	makeForm(std::string form, std::string target);
};

#endif