/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkomatsu <kkomatsu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:52:56 by kkomatsu          #+#    #+#             */
/*   Updated: 2024/10/15 14:31:06 by kkomatsu         ###   ########.fr       */
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
  
int	main(int ac, char **av)
{
    int i, j;
    std::string s;

    if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    i = 1;
    while (av[i])
    {
        s = av[i];
        j = 0;
        while (s[j])
        {
            std::cout << (char)toupper(s[j]);
            j++;
        }
        i++;
    }
    std::cout << std::endl;
    return 0;
}