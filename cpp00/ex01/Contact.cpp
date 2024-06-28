/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:06:21 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/28 23:41:28 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

using namespace	std;

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void Contact::setItems(void)
{
	cout << "Please enter the following." << endl;
	cout << "First name    : ";
	getline(cin, firstName);
	cout << "Last name     : ";
	getline(cin, lastName);
	cout << "Nick name     : ";
	getline(cin, nickName);
	cout << "Phone number  : ";
	getline(cin, phoneNumber);
	cout << "Darker secret : ";
	getline(cin, darkestSecret);
	cout << endl << "thank you!! 😻" << endl << endl;
}

void Contact::output_me_all(void)
{
	cout << "First name    : " << firstName << endl;
	cout << "Last name     : " << lastName << endl;
	cout << "Nick name     : " << nickName << endl;
	cout << "Phone number  : " << phoneNumber << endl;
	cout << "Darker secret : " << darkestSecret << endl;
}

static void	print_limit_ten(string s)
{
	int	i;
	int space_count;
	int len;

	i = 0;
	space_count = 0;
	len = s.size();
	while (len != 10 && 10 - len > 0 && i < 10 - len)
	{
		cout << " ";
		i++;
		space_count++;
	}
	while (s[i - space_count] || i < 10)
	{
		if (i == 9 && s[i + 1 - space_count])
		{
			cout << ".";
			break ;
		}
		cout << s[i - space_count];
		i++;
	}
}

void Contact::output_me_restricted(int index)
{
	print_limit_ten(to_string(index)); 
	cout << "|";
	print_limit_ten(firstName); 
	cout  << "|";
	print_limit_ten(lastName); 
	cout  << "|";
	print_limit_ten(nickName); 
	cout  << endl;
}