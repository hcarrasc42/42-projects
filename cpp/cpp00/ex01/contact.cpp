/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 10:49:25 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/16 10:51:58 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

void    Contact::set_firstName(std::string str) {
    this->firstName = str;
}

void    Contact::set_lastName(std::string str) {
    this->lastName = str;
}

void    Contact::set_nickName(std::string str) {
    this->nickName = str;
}

void    Contact::set_phoneNumber(std::string str) {
    this->phoneNumber= str;
}

void    Contact::set_darkestSecret(std::string str) {
    this->darkestSecret = str;
}

std::string     Contact::get_firstName() {
    return this->firstName;
}

std::string     Contact::get_lastName() {
    return this->lastName;
}

std::string     Contact::get_nickName() {
    return this->nickName;
}

std::string     Contact::get_phoneNumber() {
    return this->phoneNumber;
}

std::string     Contact::get_darkestSecret() {
    return this->darkestSecret;
}
