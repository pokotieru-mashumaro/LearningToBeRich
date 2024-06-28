/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:08:07 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/28 22:31:46 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    string prompt;
    PhoneBook phonebook;

    while (1)
    {
        cout << "ENTER [ADD SEARCH EXIT] 🫡: " << endl;
        cout << "> ";
        if (!getline(cin, prompt))
            break ;           
        if (prompt == "ADD")
            phonebook.addContact();
        else if (prompt == "SEARCH")
            phonebook.searchContact();
        else if (prompt == "EXIT")
            break;
        else if (prompt != "")
        {
            cout << endl;
            cout << "🚨 🤬🤬 What the fuck is this 🤬🤬 🚨" << endl;
            cout << endl;
        }
    }
    return 0;
}