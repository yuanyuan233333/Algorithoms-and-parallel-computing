//
// Created by Danilo Ardagna on 2019-08-23.
//

#include "Library.h"

int Library::find(const string &author, const string &title) const{

    return 0;

}

int Library::findAvailableBook(const string &author, const string &title) const{
    return 0;
}

void Library::addBook(const Book &book) {

}

int Library::rentBook(const string &author, const string &title) {

    return 0;
}

bool Library::returnBook(unsigned code) {

    return false;

}

void Library::print() const {

    for (size_t i = 0; i < books.size(); ++i) {
        books[i].print();
    }

}

void Library::printOldest() const {
    size_t oldest = 0;

    for (size_t i=1; i< books.size(); ++i)
        if(books[i].getYear()<books[oldest].getYear())
            oldest = i;

    books[oldest].print();
}
