//
// Created by Danilo Ardagna on 06/11/2020.
//

#ifndef POLYMORPHISMQA_BASE_H
#define POLYMORPHISMQA_BASE_H

#include <iostream>

class Base {
private:
    int a = 0;
protected:
    int b = 0;
public:

    virtual int f1();

    int f2(); // try to see if you make also this virtual and you override in Derived

    void print() const; // try to see if you make also this virtual and you override in Derived

    virtual ~Base(){};

};


#endif //POLYMORPHISMQA_BASE_H
