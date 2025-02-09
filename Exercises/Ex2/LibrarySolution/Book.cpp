//
// Created by Danilo Ardagna on 2019-08-23.
//

#include "Book.h"

using std::string;
using std::cout;
using std::endl;

Book::Book(
    unsigned c, unsigned y, unsigned p, const string &a,
    const string &t, bool av
) : code(c), year(y), pages(p), author(a), title(t), available(av)
{}

unsigned Book::get_code() const
{
  return code;
}

unsigned Book::get_year() const
{
    return year;
}

unsigned Book::get_pages() const
{
    return pages;
}

string Book::get_author() const
{
    return author;
}

string Book::get_title() const
{
    return title;
}

bool Book::is_available() const
{
  return available;
}

void Book::set_available(bool av)
{
  available = av;
}

bool Book::equal_to(const string &aut, const string &t) const
{
    return (author == aut && title == t);
}

void Book::print() const {
    cout << code << "\n"
         << author << "\n"
         << title << "\n"
         << pages << "\n"
         << year << "\n";

    if (available)
       cout << "Available";
    else
       cout << "Not available";

    cout << endl;
}
