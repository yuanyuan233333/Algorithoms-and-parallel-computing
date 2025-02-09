//
// Created by Danilo Ardagna on 2019-08-23.
//

#ifndef LIBRARY_BOOK_H
#define LIBRARY_BOOK_H

#include <string>
#include <iostream>

class Book {

private:
  unsigned code;
  unsigned year;
  unsigned pages;
  std::string author;
  std::string title;
  bool available;

public:
  Book(
      unsigned c, unsigned y, unsigned p, const std::string &a,
      const std::string &t, bool av
  );

  unsigned get_code() const;

  unsigned get_year() const;

  unsigned get_pages() const;

  std::string get_author() const;

  std::string get_title() const;

  bool is_available() const;

  void set_available(bool av);

  bool equal_to(const std::string &aut, const std::string &t) const;

  void print() const;
};

#endif //LIBRARY_BOOK_H
