#include <iostream>
using std::cout;

int main()
{
    int a = 20000;
    char c = a;
    int b = c;
    if (a != b)	    	//  != means “not equal”
        cout << "oops!: " << a << "!=" << b << '\n';
    else
        cout << "Wow! We have large characters\n";
    return 0;
}

