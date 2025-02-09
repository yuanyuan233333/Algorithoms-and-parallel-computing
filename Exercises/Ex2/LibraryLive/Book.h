//
// Created by Danilo Ardagna on 2019-08-23.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Book {
private:
    unsigned code;
    unsigned year;
    unsigned pages;
    string author;
    string title;
    bool available;



public:

    Book(unsigned code, unsigned year, unsigned pages, const string &author, const string &title, bool available);
    
    unsigned int getCode() const;

    unsigned int getYear() const;

    unsigned int getPages() const;

    const string getAuthor() const;

    void setAvailable(bool av);

    bool isAvailable() const;

    const string getTitle() const;

    bool equal_to(const string &aut, const string &t) const;

    void print() const;

};


#endif //LIBRARY_BOOK_H
