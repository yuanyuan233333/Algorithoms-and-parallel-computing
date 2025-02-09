//
// Created by Danilo Ardagna on 17/12/2020.
//

#ifndef ADDRESSBOOK_CONTACTS_H
#define ADDRESSBOOK_CONTACTS_H

#include <unordered_map>
#include <string>
#include <iostream>

class Contacts {
    std::unordered_map<std::string, std::string > data;//Name, Phone number
public:
    void add_contact(std::string name, std::string phone);
    std::string search_contact(std::string name) const;
    void print() const;
};


#endif //ADDRESSBOOK_CONTACTS_H
