//
// Created by ABEDNEGO WAMUHINDO KAMBALE on 28/10/24.
//

#ifndef EMPLOYEE__MANAGER_HPP
#define EMPLOYEE__MANAGER_HPP

#include "Developer.hpp"
#include <string>

class Manager : public Developer {
    const double m_rate = 9.5;
    const double wsh_rate = 8.5;
    unsigned int m_hours = 0;

public:
    Manager(std::string n, std::string s, unsigned int ID);

    void set_m_hours(unsigned int h);
    double salary_cal() const override;
};

#endif //EMPLOYEE__MANAGER_HPP
