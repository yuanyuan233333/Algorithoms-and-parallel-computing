// Developer.cpp
// Implementation of Developer class

#include "Developer.hpp"

Developer::Developer(std::string n, std::string s, unsigned int ID)
        : Employee(n, s, ID) {}

void Developer::set_wsh_hours(unsigned int hours) {
    wsh_hours = hours;
}

double Developer::salary_cal() const {
    double wsh_pay = (wsh_hours * wsh_rate);
    double w_pay = (work_hours - wsh_hours) * pay_rate;
    return wsh_pay + w_pay;
}
