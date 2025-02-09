#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

int main() {
    vector<string> articles = {"a", "an", "the"};
    vector<string> v5{"hi"}; // list initialization: v5 has one element

    vector<string> v6(v5); // OK, v6 has its own elements, are
                           // copies of v5’s!
    vector<string> v7(10); // v7 has ten default-initialized elements

    vector<string> v8{10, "hi"}; // v8 has ten elements with value
                                      // "hi"
    vector<string> v9(10, "hi"); // v9 has ten elements with value
                                      // "hi", as above

    return 0;
}