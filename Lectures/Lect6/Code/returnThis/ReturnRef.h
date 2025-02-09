//
// Created by Federica Filippini on 09/10/23.
//

#ifndef RETURNTHIS_RETURNREF_H
#define RETURNTHIS_RETURNREF_H

#include <iostream>

class ReturnRef {

private:
  int x;

public:
  explicit ReturnRef (int _x): x(_x) {}

  void set_x (int _x) {x = _x;}

  ReturnRef& operator= (const ReturnRef& rhs);
  ReturnRef& operator+= (const ReturnRef& rhs);

  void print (void) const;
};


#endif //RETURNTHIS_RETURNREF_H
