/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:52:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/06/28 17:47:53 by kkomatsu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
*/

#include <iostream>
 
using namespace std;
 
int	main(int ac, char **av)
{
    int i, j;
    string s;

    if (ac < 2)
	{
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << endl;
		return (0);
	}
    i = 1;
    while (av[i])
    {
        s = av[i];
        j = 0;
        while (s[j])
        {
            cout << (char)toupper(s[j]);
            j++;
        }
        i++;
    }
    cout << endl;
    return 0;
}