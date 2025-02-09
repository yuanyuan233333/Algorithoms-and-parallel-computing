//
// Created by Danilo Ardagna on 2019-08-23.
//

#include "Library.h"

using std::vector;
using std::string;
using std::cerr;
using std::endl;

int Library::find(const string &author, const string &title) const
{
    int return_index = -1;
    bool book_found = false;

    for (size_t i = 0; i < books.size() && !book_found; ++i)
        if (books[i].equal_to(author,title))
        {
            book_found = true;
            return_index = i;
        }

    return return_index;

}

int Library::find_available_book(const string &author, const string &title) const
{
    int return_index = -1;
    bool book_found = false;

    for (size_t i =0; i < books.size() && !book_found; ++i)
        if (books[i].equal_to(author,title) && books[i].is_available())
        {
            book_found = true;
            return_index = i;
        }

    return return_index;
}

void Library::add_book(const Book &book)
{
    books.push_back(book);
}

int Library::rent_book(const string &author, const string &title)
{
    int index = find_available_book(author,title);

    if (index == -1)
    {
        cerr << "Book not available" << endl;
        return -1;
    }
    else
    {
        books[index].set_available(false);
        return books[index].get_code();
    }
}

bool Library::return_book(unsigned code)
{
    bool book_found = false;
    size_t i;

    for (i = 0; i < books.size() && !book_found; ++i)
        if (books[i].get_code() == code && !books[i].is_available())
            book_found = true;

    if (book_found)
    {
        books[i-1].set_available(true);
        return true;
    }
    else
    {
        cerr << "Book already in store" << endl;
        return false;
    }
}

void Library::print() const
{
    for (size_t i = 0; i < books.size(); ++i)
        books[i].print();
}

void Library::print_oldest() const
{
    size_t oldest = 0;

    for (size_t i = 1; i < books.size(); ++i)
        if(books[i].get_year() < books[oldest].get_year())
            oldest = i;

    books[oldest].print();
}
