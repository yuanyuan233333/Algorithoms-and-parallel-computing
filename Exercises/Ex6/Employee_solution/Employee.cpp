// Employee_solution.cpp
// Implementation of Employee_solution class

#include "Employee.hpp"

Employee::Employee(std::string n, std::string s, unsigned int ID)
        : name(n), surname(s), employee_ID(ID) {}

void Employee::set_work_hours(unsigned int hours) {
    work_hours = hours;
}

void Employee::print() const {
    std::cout << name << " " << surname << " " << employee_ID << std::endl;
}

double Employee::salary_cal() const {
    return pay_rate * work_hours;
}
