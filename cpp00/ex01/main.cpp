/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:07 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/10/15 14:34:27 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main(void)
{
    std::string prompt;
    PhoneBook phonebook;

    while (1)
    {
        std::cout << "ENTER [ADD SEARCH EXIT] 🫡: " << std::endl;
        std::cout << "> ";
        if (!getline(std::cin, prompt))
            break ;           
        if (prompt == "ADD")
            phonebook.addContact();
        else if (prompt == "SEARCH")
            phonebook.searchContact();
        else if (prompt == "EXIT")
            break;
        else if (prompt != "")
        {
            std::cout << std::endl;
            std::cout << "🚨 🤬🤬 What the fuck is this 🤬🤬 🚨" << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}