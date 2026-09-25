/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:45 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:35 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void    ft_menu(void) {
    std::cout << "============-MENU-============" << std::endl;
    std::cout << "=         1- ADD             =" << std::endl;
    std::cout << "=         2- SRCH            =" << std::endl;
    std::cout << "=         3- EXIT            =" << std::endl;
    std::cout << "==============================" << std::endl;
}

int main(void) {
    PhoneBook phonebook;
    std::string input;
    int max = 1;

    ft_menu();
    while (1) {
        std::cout << "Enter a command > ";
        std::cin >> input;

        if (input.empty())
            continue;
        if (input == "EXIT") {
            std::cout << "You have left PhoneBook" << std::endl;
            break;
        }
        else if (input == "ADD") {
            if (max <= 8) {
                std::cout << "---Add contact---" << std::endl;
                max += 1;
                phonebook.add_newContact();
            }
            else
                std::cout << "Phonebook is full. Try another command or enter EXIT to remove all contacts" << std::endl;
        }
        else if (input == "SRCH") {
            std::cout << "---Search contact---" << std::endl;
            if (max > 1) {
                phonebook.show_contacts();
                phonebook.search_contact();
            }
            else
                std::cout << "Phonebook is empty." << std::endl;
        }
        else {
            std::cout << "Invalid command. Try another." << std::endl;
            continue;
        }
    }
    return (0);
}
