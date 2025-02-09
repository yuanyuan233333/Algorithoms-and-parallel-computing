//
// Created by ABEDNEGO WAMUHINDO KAMBALE on 28/10/24.
//
#ifndef EMPLOYEE__EMPLOYEE_HPP
#define EMPLOYEE__EMPLOYEE_HPP

#include <string>
#include <iostream>
class Employee {
protected:
    std::string name;
    std::string surname;
    unsigned int employee_ID;
    const double pay_rate = 7.5;
    unsigned int work_hours = 0;

public:
    Employee(std::string n, std::string s, unsigned int ID);

    void set_work_hours(unsigned int hours);
    void print() const;
    virtual double salary_cal() const;
};

#endif //EMPLOYEE__EMPLOYEE_HPP
