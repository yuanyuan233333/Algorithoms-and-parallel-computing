#include <iostream>
#include "Contacts.h"

int main() {

    Contacts c;
    c.add_contact("Danilo", "323 1");
    c.add_contact("Federica", "333 2");
    c.add_contact("Danilo", "323 3");

    std::cout << "Danilo " << c.search_contact("Danilo") << std::endl;
    std::cout << "Marco " << c.search_contact("Marco") << std::endl;
    std::cout << "Federica " << c.search_contact("Federica") << std::endl;

    std::cout << "Address Book content"<<std::endl;

    c.print();

    return 0;
}
