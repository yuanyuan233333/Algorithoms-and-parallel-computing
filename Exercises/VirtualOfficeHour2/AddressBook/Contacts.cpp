//
// Created by Danilo Ardagna on 17/12/2020.
//

#include "Contacts.h"


void Contacts::add_contact(std::string name, std::string phone) {
    data[name] = phone;
}

std::string Contacts::search_contact(std::string name) const {

    if (data.find(name)!= data.cend())
        return data.at(name);
        //return data[name];
    else
        return "";
}

void Contacts::print() const {
    for (const auto & d : data )
        std::cout << d.first << " " << d.second << std::endl;
}
