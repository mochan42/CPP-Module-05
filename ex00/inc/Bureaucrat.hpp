/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 13:25:02 by mochan            #+#    #+#             */
/*   Updated: 2023/03/28 18:37:14 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>

class	Bureaucrat
{
	public:
		// CONSTRUCTORS - DESTRUCTOR
		Bureaucrat(); // Default constructor
		Bureaucrat(const Bureaucrat& other); // Default copy constructor
		~Bureaucrat(); // Destructor
		
		// OVERLOAD OPERATOR
		Bureaucrat& operator=(const Bureaucrat& src);
		
		// GETTERS - SETTERS
		std::string	getName(void) const;
		// void		setName(const std::string setName) const;
		int			getGrade(void) const;
		// void		setGrade(int setGrade) const;
		
		// MEMBER FUNCTIONS
		void	GradeTooHighException( void );
		void	GradeTooLowException( void );
		void	incrementGrade( void );
		void	decrementGrade( void );
		
	private:
		const std::string	_name;
		int					_grade;
};

std::ostream& operator<<( std::ostream& outputStream, const Bureaucrat& bureaucrat );

#endif