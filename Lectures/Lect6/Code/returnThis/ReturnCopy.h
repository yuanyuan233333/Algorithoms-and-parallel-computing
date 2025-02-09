//
// Created by Federica Filippini on 09/10/23.
//

#ifndef RETURNTHIS_RETURNCOPY_H
#define RETURNTHIS_RETURNCOPY_H

#include <iostream>

class ReturnCopy {

private:
  int x;

public:
  explicit ReturnCopy (int _x): x(_x) {}

  void set_x (int _x) {x = _x;}

  ReturnCopy operator= (const ReturnCopy& rhs);
  ReturnCopy operator+= (const ReturnCopy& rhs);

  void print (void) const;
};


#endif //RETURNTHIS_RETURNCOPY_H
