#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {

    Book b1(1, 2013, 1399, "S. B. Lippman", "C++ primer", true);

    Book b2(2, 2013, 1361, "B. Stroustrup", "The C++ programming language", true);


    b1.print();
    b2.print();

    /*

    Library lib;

    lib.addBook(b1);
    lib.addBook(b2);
    lib.addBook(Book(1, 2013, 1399, "S. B. Lippman", "C++ primer", true));

    lib.rentBook("S. B. Lippman", "C++ primer");

    lib.print();
    cout << "****************+"<< endl;
    lib.rentBook("S. B. Lippman", "C++ primer");
    lib.print();
    cout << "****************+"<< endl;

    lib.returnBook(1);
    lib.print();
    cout << "****************+"<< endl;

    lib.returnBook(1);
    lib.print();

    cout << "****************+"<< endl;

    cout << "Oldest book" << endl;

    lib.printOldest();
     */
    return 0;
}