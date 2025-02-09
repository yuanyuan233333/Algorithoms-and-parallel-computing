// Manager.cpp
// Implementation of Manager class

#include "Manager.hpp"

Manager::Manager(std::string n, std::string s, unsigned int ID)
        : Developer(n, s, ID) {}

void Manager::set_m_hours(unsigned int h) {
    m_hours = h;
}

double Manager::salary_cal() const {
    double wsh_pay = (wsh_hours * wsh_rate);
    double m_pay = (m_hours * m_rate);
    double w_pay = (work_hours - wsh_hours - m_hours) * pay_rate;
    return wsh_pay + w_pay + m_pay;
}
