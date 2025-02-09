//
// Created by Federica Filippini on 09/10/23.
//

#include "ReturnRef.h"

ReturnRef& ReturnRef::operator= (const ReturnRef &rhs)
{
  x = rhs.x;
  return *this;
}

ReturnRef& ReturnRef::operator+= (const ReturnRef &rhs)
{
  x += rhs.x;
  return *this;
}

void ReturnRef::print (void) const
{
  std::cout << "(ReturnRef) x = " << x << std::endl;
}
