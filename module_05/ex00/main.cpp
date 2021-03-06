/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 11:04:48 by allanganoun       #+#    #+#             */
/*   Updated: 2021/04/20 11:46:29 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
		Bureaucrat eric("Eric", 147);
		std::cout << eric << std::endl;
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
