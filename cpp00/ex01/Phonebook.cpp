/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:03:16 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/28 23:48:20 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace	std;

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

static int	check_id_str(string id_str)
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
	cout << "       Id |First Name| LastName | Nickname " << endl;
	cout << "-------------------------------------------" << endl;
}

void PhoneBook::searchContact(void)
{
	string id_str;
    int i;
	int id;

	if (_total_contacts == 0)
	{
		cout << endl << "🚨 🤬🤬 contact does not exist🤬🤬 🚨" << endl << endl;
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
	cout << "Enter the id of the search target : ";
	getline(cin, id_str);
    if (!check_id_str(id_str) || id_str == "")
    {
        cout << endl << "🚨 🤬🤬 only accepts positive integers 🤬🤬 🚨" << endl << endl;
        return ;
    }
	id = stoi(id_str);
    if (id >= _total_contacts)
    {
        cout << endl << "🚨 🤬🤬 This id does not exist 🤬🤬 🚨" << endl << endl;
        return ;
    }
	cout << endl;
	_contacts[id].output_me_all();
	cout << endl;
}