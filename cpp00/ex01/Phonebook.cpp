/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:03:16 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/10/15 14:35:13 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

PhoneBook::PhoneBook(void)
{
	_total_contacts = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::addContact(void)
{
	int	i;

	if (_total_contacts == 8)
	{
		i = 0;
		while (i < 7)
		{
			_contacts[i] = _contacts[i + 1];
			i++;
		}
		_contacts[_total_contacts - 1].setItems();
	}
	else
	{
		_total_contacts++;
		_contacts[_total_contacts - 1].setItems();
	}
}

static int	check_id_str(std::string id_str)
{
	int	i;

	i = 0;
	while (id_str[i])
	{
		if (id_str[i] < '0' || '9' < id_str[i])
			return (0);
		i++;
	}
	return (1);
}

static void put_title(void)
{
	std::cout << "       Id |First Name| LastName | Nickname " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
}

void PhoneBook::searchContact(void)
{
	std::string id_str;
    int i;
	int id;

	if (_total_contacts == 0)
	{
		std::cout << std::endl << "🚨 🤬🤬 contact does not exist🤬🤬 🚨" << std::endl << std::endl;
		return ;
	}
    i = 0;
	put_title();
    while (i < _total_contacts) 
    {
        _contacts[i].output_me_restricted(i);
        i++;
    }
	id = -1;
	std::cout << "Enter the id of the search target : ";
	getline(std::cin, id_str);
    if (!check_id_str(id_str) || id_str == "")
    {
        std::cout << std::endl << "🚨 🤬🤬 only accepts positive integers 🤬🤬 🚨" << std::endl << std::endl;
        return ;
    }
	id = stoi(id_str);
    if (id >= _total_contacts)
    {
        std::cout << std::endl << "🚨 🤬🤬 This id does not exist 🤬🤬 🚨" << std::endl << std::endl;
        return ;
    }
	std::cout << std::endl;
	_contacts[id].output_me_all();
	std::cout << std::endl;
}