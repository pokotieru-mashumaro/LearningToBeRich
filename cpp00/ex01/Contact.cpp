/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:06:21 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/10/15 14:34:00 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iomanip>
#include <iostream>
#include <string>

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
	std::cout << "Please enter the following." << std::endl;
	std::cout << "First name    : ";
	getline(std::cin, firstName);
	std::cout << "Last name     : ";
	getline(std::cin, lastName);
	std::cout << "Nick name     : ";
	getline(std::cin, nickName);
	std::cout << "Phone number  : ";
	getline(std::cin, phoneNumber);
	std::cout << "Darker secret : ";
	getline(std::cin, darkestSecret);
	std::cout << std::endl << "thank you!! 😻" << std::endl << std::endl;
}

void Contact::output_me_all(void)
{
	std::cout << "First name    : " << firstName << std::endl;
	std::cout << "Last name     : " << lastName << std::endl;
	std::cout << "Nick name     : " << nickName << std::endl;
	std::cout << "Phone number  : " << phoneNumber << std::endl;
	std::cout << "Darker secret : " << darkestSecret << std::endl;
}

static void	print_limit_ten(std::string s)
{
	int	i;
	int space_count;
	int len;

	i = 0;
	space_count = 0;
	len = s.size();
	while (len != 10 && 10 - len > 0 && i < 10 - len)
	{
		std::cout << " ";
		i++;
		space_count++;
	}
	while (s[i - space_count] || i < 10)
	{
		if (i == 9 && s[i + 1 - space_count])
		{
			std::cout << ".";
			break ;
		}
		std::cout << s[i - space_count];
		i++;
	}
}

void Contact::output_me_restricted(int index)
{
	print_limit_ten(std::to_string(index)); 
	std::cout << "|";
	print_limit_ten(firstName); 
	std::cout  << "|";
	print_limit_ten(lastName); 
	std::cout  << "|";
	print_limit_ten(nickName); 
	std::cout << std::endl;
}