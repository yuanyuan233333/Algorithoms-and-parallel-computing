#ifndef SECRETARY_H
#define SECRETARY_H

#include "Employee.hpp"

class Secretary: public Employee {

public:

    Secretary (const std::string& n, const std::string& sn, unsigned id): 
              Employee(n, sn, id) {} 
    
    double salary_cal (void) const override {return (work_hours * pay_rate);}

};

#endif /* SECRETARY_H */
