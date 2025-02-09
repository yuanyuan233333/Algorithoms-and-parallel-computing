//
// Created by Danilo Ardagna on 06/11/2020.
//

#ifndef POLYMORPHISMQA_DERIVED_H
#define POLYMORPHISMQA_DERIVED_H

#include "Base.h"

class Derived : public Base {

private:
    int c = 0;

public:
    int f1() override;
    int f2() ;// override;
    void print() const; // override;
    virtual ~Derived(){};
};


#endif //POLYMORPHISMQA_DERIVED_H
