//
// Created by Federica Filippini on 09/10/23.
//

#include "ReturnCopy.h"

ReturnCopy ReturnCopy::operator= (const ReturnCopy &rhs)
{
  x = rhs.x;
  return *this;
}

ReturnCopy ReturnCopy::operator+= (const ReturnCopy &rhs)
{
  x += rhs.x;
  return *this;
}

void ReturnCopy::print (void) const
{
  std::cout << "(ReturnCopy) x = " << x << std::endl;
}
