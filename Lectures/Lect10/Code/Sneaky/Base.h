//
// Created by Danilo Ardagna on 19/10/2019.
//

#ifndef SNEAKY_BASE_H
#define SNEAKY_BASE_H


class Base {
protected:
    int prot_mem = 0;
public:
    int getProtMem() const;

    void setProtMem(int protMem);
    // protected member
};


#endif //SNEAKY_BASE_H
