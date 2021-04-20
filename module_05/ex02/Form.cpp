/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 15:21:49 by allanganoun       #+#    #+#             */
/*   Updated: 2021/04/20 18:06:05 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form()
{
}

Form::Form(std::string const &name, int sign, int exec)
:name(name), _signed(false), sign_grade(sign), exec_grade(exec)
{
	std::cout << "Form created." << std::endl;
	if (this->sign_grade < 1 || this->exec_grade < 1)
		throw GradeTooHighException();
	else if (this->sign_grade > 150 || this->exec_grade > 150)
		throw GradeTooLowException();
}

Form::Form(Form	const &copied)
{
	*this = copied;
	std::cout << "Form copy created." << std::endl;
}

Form::~Form()
{
	std::cout << "Form destroyed." << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("[FORM] Grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("[FORM] Grade is too low.");
}

Form &Form::operator=(Form const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_signed = rhs._signed;
	this->sign_grade = rhs.sign_grade;
	this->exec_grade = rhs.exec_grade;
	return (*this);
}

std::string const &Form::getName() const
{
	return (this->name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int	Form::getSignGrade() const
{
	return (this->sign_grade);
}

int	Form::getExecGrade() const
{
	return (this->exec_grade);
}

void	Form::beSigned(Bureaucrat const &b)
{
	if (b.getGrade() < this->sign_grade)
		this->_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, Form const &tmp)
{
	if (tmp.getSigned() == true)
		out << tmp.getName() << " is signed.\n"
			<< "Grade required to sign : "
				<< tmp.getSignGrade() << "\n" << "Grade required to execute : "
					<< tmp.getExecGrade();
	else
		out << tmp.getName() << " is not signed.\n"
			<< "Grade required to sign : "
				<< tmp.getSignGrade() << "\n" << "Grade required to execute : "
					<< tmp.getExecGrade();
	return (out);
}
