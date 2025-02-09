#include <iostream>
#include <memory>

using std::shared_ptr;
using std::make_shared;

int main()
{
    shared_ptr<int> p1 = make_shared<int>(2);

    std::cout << p1.use_count() << std::endl;

    shared_ptr<int> p2(p1);

    std::cout << p1.use_count() << "; " << p2.use_count() << std::endl;

    shared_ptr<int> p3 = make_shared<int>(10);
    std::cout << p3.use_count() << std::endl;

    p1 = p3;
    std::cout << p1.use_count() << "; " 
              << p2.use_count() << "; " 
              << p3.use_count() << std::endl;

    return 0;
}
