/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochan <mochan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:40:26 by mochan            #+#    #+#             */
/*   Updated: 2023/03/29 21:30:12 by mochan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"

//======== CONSTRUCTORS =========================================================================

ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm(), _target("Default target")
{
	std::cout << BLU << "Default constructor called from ShrubberyCreationForm" << D << "\n";
}

// Initialization of the derived class is made with the corresponding constructor of the immediate base class
ShrubberyCreationForm::ShrubberyCreationForm(std::string const target)
	: AForm("Random ShrubberyCreationForm Name", false, 145, 137), _target(target)
{
	std::cout << BLU << "Initialized constructor called from ShrubberyCreationForm" << D << "\n";
	this->_target = (target + "_shrubbery");
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << BLU << "Copy constructor called from ShrubberyCreationForm" << D << "\n";
	*this = src;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
	std::cout << BLU << "Copy assignment operator called from ShrubberyCreationForm" << D << "\n";
	this->_target =src.getTarget();
	return (*this);
}

//======== DESTRUCTOR ===========================================================================
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << CY << "Destructor called from ShrubberyCreationForm" << D << "\n";
}


//==== GETTERS / SETTERS ========================================================================
std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}


//======== MEMBER FUNCTIONS =====================================================================
void		ShrubberyCreationForm::beSigned(Bureaucrat bureaucrat)
{
	try
	{
		if ( bureaucrat.getGrade() > getGradeToSign() )
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (bureaucrat.getGrade() <= getGradeToSign() )
	{
		setIsSigned(true);
		std::cout << GREEN << "ShrubberyCreationForm " << BKLIGRN << getName() << GREEN << " is signed" << D << "\n";
	}
	else
		std::cout << RED << "ShrubberyCreationForm " << BKLIGRN << getName() << RED << " is not signed" << D << "\n";
}

bool		ShrubberyCreationForm::execute(Bureaucrat const & obj) const
{
	bool	formIsExecuted = false;

	try
	{
		if (getIsSigned() == false)
			throw GradeTooLowException();
	}
	catch (std::exception & e)
	{
		std::cout << RED << "Exception caught for " << getName() << " : " << e.what() << D << "\n";
	}
	if (getIsSigned() == true && obj.getGrade() <= getGradeToExec() )
	{
		std::cout << GREEN << "Bureaucrat " << BKLIGRN << obj.getName() << GREEN << " authorized to draw Tree" << D << "\n";
		std::ofstream outputFile;

		outputFile.open(_target);

		// ASCII art string
		std::string treeArt =
		"###########################'`################################\n"
		"###########################  V##'############################\n"
		"#########################V'  `V  ############################\n"
		"########################V'      ,############################\n"
		"#########`#############V      ,A###########################V\n"
		"########' `###########V      ,###########################V',#\n"
		"######V'   ###########l      ,####################V~~~~'',###\n"
		"#####V'    ###########l      ##P' ###########V~~'   ,A#######\n"
		"#####l      d#########l      V'  ,#######V~'       A#########\n"
		"#####l      ##########l         ,####V''         ,###########\n"
		"#####l        `V######l        ,###V'   .....;A##############\n"
		"#####A,         `######A,     ,##V' ,A#######################\n"
		"#######A,        `######A,    #V'  A########'''''##########''\n"
		"##########,,,       `####A,           `#''           '''  ,,,\n"
		"#############A,                               ,,,     ,######\n"
		"######################oooo,                 ;####, ,#########\n"
		"##################P'                   A,   ;#####V##########\n"
		"#####P'    ''''       ,###             `#,     `V############\n"
		"##P'                ,d###;              ##,       `V#########\n"
		"##########A,,   #########A              )##,    ##A,..,ooA###\n"
		"#############A, Y#########A,            )####, ,#############\n"
		"###############A ############A,        ,###### ##############\n"
		"###############################       ,#######V##############\n"
		"###############################      ,#######################\n"
		"##############################P    ,d########################\n"
		"##############################'    d#########################\n"
		"##############################     ##########################\n"
		"##############################     ##########################\n"
		"#############################P     ##########################\n"
		"#############################'     ##########################\n"
		"############################P      ##########################\n"
		"###########################P'     ;##########################\n"
		"###########################'     ,###########################\n"
		"##########################       ############################\n"
		"#########################       ,############################\n"
		"########################        d###########P'    `Y#########\n"
		"#######################        ,############        #########\n"
		"######################        ,#############        #########\n"
		"#####################        ,##############b.    ,d#########\n"
		"####################        ,################################\n"
		"###################         #################################\n"
		"##################          #######################P'  `V##P'\n"
		"#######P'     `V#           ###################P'\n"
		"#####P'                    ,#################P'\n"
		"###P'                      d##############P''\n"
		"##P'                       V##############'\n"
		"#P'                         `V###########'\n"
		"#'                             `V##P'\n";

		if (outputFile.is_open())
		{
			outputFile << treeArt;
			outputFile.close();
		} else {
			std::cout << "Error opening file.\n";
		}
		formIsExecuted = true;
		return (formIsExecuted);
	}
	else
	{
		std::cout << RED << "Bureaucrat " << BKLIGRN << obj.getName() << RED << " NOT authorized to draw Tree" << D << "\n";
		return (formIsExecuted);
	}
}

//=============== FUNCTIONS =====================================================================
std::ostream& operator<<( std::ostream& outputStream, const ShrubberyCreationForm& ShrubberyCreationForm )
{
	outputStream << BKLIGRN << ShrubberyCreationForm.getName() << YELL << ", with boolean isSigned = " << LIGRN << ShrubberyCreationForm.getIsSigned() << YELL << ", Grade to Sign = " << LIGRN << ShrubberyCreationForm.getGradeToSign() << YELL << ", Grade to Execute = " << LIGRN << ShrubberyCreationForm.getGradeToExec() << D << "\n";
	return (outputStream);
}