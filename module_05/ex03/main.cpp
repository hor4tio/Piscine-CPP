/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:04:48 by allanganoun       #+#    #+#             */
/*   Updated: 2021/04/21 20:40:39 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main ()
{
	try
	{
		Bureaucrat jim("Jim", 150);
		std::cout << jim << std::endl;
		jim.GradeDecrease();
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat tom("Tom", 1);
		std::cout << tom << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat eric("Eric", 130);
		std::cout << eric << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "===================== testing all form type =====================" << std::endl;

	try
	{
		Intern i;
		Form *form;
		Bureaucrat eric("Eric", 120);
		Bureaucrat tom("Tom", 1);
		Bureaucrat jim("Jim", 150);
		form = i.makeform("ShrubberyCreation", "bender");
		std::cout << *form << std::endl;
		tom.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
