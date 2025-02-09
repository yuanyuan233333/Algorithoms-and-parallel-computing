#include <iostream>
#include "MatlabVector.h"

using std::cout;
using std::endl;

int main() {
    MatlabVector v;
    v[0] = 1;
    v[1] = 3;
    cout << "v content" << endl;
    v.print();
    v[3] = 4;
    cout << "v content" << endl;
    v.print();

    double d = v[4];
    cout << "v content" << endl;
    v.print();

    for (unsigned i=0; i<v.size(); ++i) {
        v[i] = i;
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "v content" << endl;
    v.print();

    MatlabVector v2 = v*3;
    cout << "v2 content" << endl;
    v2.print();

    //MatlabVector v3 = v + v2;

    MatlabVector v3 = v.operator+( v2);


    cout << "v3 content" << endl;
    v3.print();

    return 0;
}
