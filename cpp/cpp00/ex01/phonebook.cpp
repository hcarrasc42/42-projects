/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:30 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/16 11:03:58 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
    index = 0;
}

void    PhoneBook::add_newContact() {
    Contact tmpContact;

    std::cout << "First name: ";
    std::cin >> _firstName;
    tmpContact.set_firstName(_firstName);
    std::cout << "Last name: ";
    std::cin >> _lastName;
    tmpContact.set_lastName(_lastName);
    std::cout << "Nick name: ";
    std::cin >> _nickName;
    tmpContact.set_nickName(_nickName);
    std::cout << "Phone number: ";
    std::cin >> _phoneNumber;
    tmpContact.set_phoneNumber(_phoneNumber);
    std::cout << "Darkest secret: ";
    std::cin >> _darkestSecret;
    tmpContact.set_darkestSecret(_darkestSecret);
    this->index += 1;
    if (this->index <= 8) {
        this->contacts[this->index] = tmpContact;
        std::cout << "Conatact added" << std::endl;
    }
}

std::string get_newSize(std::string str) {
    if (str.length() > 10) {
        str.erase(str.begin() + 9, str.end());
        str.append(".");
    }
    return (str);
}

void    PhoneBook::show_contacts() {
    int i = 1;

    std::cout << "|  INDEX   |FIRST NAME|LAST NAME | NICKNAME |"<< std::endl;
    while (i <= this->index) {
        std::cout << "|" << std::setw(10) << i
        << "|" << std::setw(10) << get_newSize(contacts[i].get_firstName())
        << "|" << std::setw(10) << get_newSize(contacts[i].get_lastName())
        << "|" << std::setw(10) << get_newSize(contacts[i].get_nickName())
        << "|" << std::endl;

        i++;
    }
}

void    PhoneBook::search_contact() {
    int num;

    std::cout << "Choose a contatc using the index> ";
    std::cin >> num;

    if (std::cin.fail())
        std::cout << "Index invalid" << std::endl;
    else {
        if (num > 0 && num <= this->index) {
            std::cout << "First name: " << contacts[num].get_firstName() << std::endl;
            std::cout << "Last name: " << contacts[num].get_lastName() << std::endl;
            std::cout << "Nick name: " << contacts[num].get_nickName() << std::endl;
            std::cout << "Phone number: " << contacts[num].get_phoneNumber() << std::endl;
            std::cout << "Darkest secret: " << contacts[num].get_darkestSecret() << std::endl;
        }
        else
            std::cout << "Index invalid" << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}
