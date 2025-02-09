#include <iostream>
#include "MatlabVector.h"

using std::cout;
using std::endl;

int main() {
    MatlabVector v;
    v.set(0, 1);
    v.set(1, 3);
    std::cout << "v content" << std::endl;
    v.print();
    v.set(3,4);
    std::cout << "v content" << std::endl;
    v.print();

    double d = v.get(4);
    std::cout << "v content" << std::endl;
    v.print();

    for (unsigned i = 0; i < v.size(); ++i) {// pretty ugly:
        v.set(i,i);
        cout << v.get(i) << " ";
    }
    cout << endl;

    std::cout << "v content" << std::endl;
    v.print();

    MatlabVector v2 = v * 3 ;// unfortunately 3*v does not work
    std::cout << "v2 content" << std::endl;
    v2.print();
    MatlabVector v3 = v+v2;
    std::cout << "v3 content" << std::endl;
    v3.print();

    return 0;
}
