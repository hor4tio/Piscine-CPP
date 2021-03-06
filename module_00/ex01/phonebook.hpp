/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alganoun <alganoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 14:08:51 by alganoun          #+#    #+#             */
/*   Updated: 2021/03/22 14:44:45 by alganoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>

# define CAPS_OFF			0
# define CAPS_ON			1
# define WELCOME			"\n---------- PHONEBOOK 1.0 by Alganoun ----------\n"
# define ADD_MAN			"- Type ADD to add a contact\n"
# define SEARCH_MAN			"- Type SEARCH to see all added contact\n"
# define EXIT_MAN			"- Type EXIT to exit the progam\n"
# define COMMAND_ERROR		"ERROR : command not found.\n"
# define SEARCH_MORE		"\nYou can enter the contact n. to get more informations on it"
# define MENU_BACK			"Type MENU to go to the Main Menu\n"
# define ERROR				"Something went wrong with the phonebook."
# define NAME_ERROR			"Please enter a correct name."
# define DATE_ERROR			"Bad format, please use (MM/DD/YY) format."
# define ERROR				"Something went wrong with the phonebook."
# define MONTH_ERROR		"Bad month format, please use (MM/DD/YY) format."
# define DAY_ERROR			"Bad day format, please use (MM/DD/YY) format."
# define YEAR_ERROR			"Bad year format, please use (MM/DD/YY) format."
# define MAIL_ERROR			"Please use a correct mail adress (example@example.com)"
# define PHONE_ERROR		"Please use a correct phone number"
# define MAX_CONTACT		"Phonebook max capacity, you can't add any more contacts"
# define MORE_INFO			"More info about "
# define EXIT_WARNING 		"\n/!\\ ALL contacts will be removed, Continue ? (Y/N)"
# define EXIT_MESSAGE		" Thank you for using Phonebook 1.0, see you soon."
# define TAB_LINE			"\n---------------------------------------------\n"
# define TAB_TITLE			"|CONTACT N.|FIRST NAME| LAST NAME|   LOGIN  |"
# define TAB_LINE_SMALL		"----------"

class	contact
{
	private :

	char		contact_n[1];
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string login;
	std::string postal_adress;
	std::string email_adress;
	std::string phone_number;
	std::string bday_date;
	std::string fav_meal;
	std::string under_color;
	std::string dark_secrets;

	public :

	int			set_info(std::string info, std::string *line);
	int			check_numbers(std::string str);
	int			get_contact_info(int n);
	void		display_contact_list();
	void		print_data(std::string data);
	void		display_specific_info();
	int			check_name(std::string str);
	int			check_number(std::string str);
	int			check_birthday(std::string str);
	int			check_mail(std::string str);

};

int		write_error(std::string str);
int		check_number(std::string str);
int		check_birthday(std::string str);
int		check_mail(std::string str);
int		smart_getline(std::string *str, int option);
#endif
