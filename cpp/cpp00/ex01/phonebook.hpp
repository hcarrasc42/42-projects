/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasc <hcarrasc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 13:25:37 by hcarrasc          #+#    #+#             */
/*   Updated: 2023/10/16 11:02:24 by hcarrasc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook {
    private:
        int             index;
        Contact         contacts[8];
        std::string     _firstName;
        std::string     _lastName;
        std::string     _nickName;
        std::string     _phoneNumber;
        std::string     _darkestSecret;
    public:
        PhoneBook();
        ~PhoneBook(){};

        void            add_newContact();
        void            search_contact();
        void            show_contacts();
};

#endif
