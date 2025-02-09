//
// Created by ABEDNEGO WAMUHINDO KAMBALE on 28/10/24.
//
#ifndef EMPLOYEE__DEVELOPER_HPP
#define EMPLOYEE__DEVELOPER_HPP

#include "Employee.hpp"

class Developer : public Employee {
protected:
    const double wsh_rate = 8.0;
    unsigned int wsh_hours = 0;

public:
    Developer(std::string n, std::string s, unsigned int ID);

    void set_wsh_hours(unsigned int hours);
    double salary_cal() const override;
};

#endif //EMPLOYEE__DEVELOPER_HPP
