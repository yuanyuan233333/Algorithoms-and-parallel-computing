#include "ReturnRef.h"
#include "ReturnCopy.h"

void print_msg (const std::string& msg);
void check_increment_operator (void);
void check_assignment_operator (void);

int main (void)
{
  check_increment_operator();

  //check_assignment_operator();

  return 0;
}

void print_msg (const std::string& msg)
{
  std::cout << "---------------------------------------------" << std::endl;
  std::cout << msg << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
}

void check_increment_operator (void)
{
  print_msg("(check_increment_operator) base types");

  int a = 0;
  int b = 1;
  int c = 2;
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  a += b += c;
  std::cout << "a += b += c ---> ";
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  a = 0;
  b = 1;
  c = 2;

  (a += b) += c;
  std::cout << "(a += b) += c ---> ";
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  print_msg("(check_increment_operator) ReturnRef");
  ReturnRef rr0(0), rr1(1), rr2(2);
  rr0.print();
  rr1.print();
  rr2.print();

  print_msg("rr0 += rr1 += rr2");
  rr0 += rr1 += rr2;
  rr0.print();
  rr1.print();
  rr2.print();

  rr0.set_x(0);
  rr1.set_x(1);
  rr2.set_x(2);

  print_msg("(rr0 += rr1) += rr2");
  (rr0 += rr1) += rr2;
  rr0.print();
  rr1.print();
  rr2.print();

  print_msg("(check_increment_operator) ReturnCopy");
  ReturnCopy rc0(0), rc1(1), rc2(2);
  rc0.print();
  rc1.print();
  rc2.print();

  print_msg("rc0 += rc1 += rc2");
  rc0 += rc1 += rc2;
  rc0.print();
  rc1.print();
  rc2.print();

  rc0.set_x(0);
  rc1.set_x(1);
  rc2.set_x(2);

  print_msg("(rc0 += rc1) += rc2");
  (rc0 += rc1) += rc2;
  rc0.print();
  rc1.print();
  rc2.print();
}

void check_assignment_operator (void)
{
  print_msg("(check_assignment_operator) base types");

  int a = 0;
  int b = 1;
  int c = 2;
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  a = b = c;
  std::cout << "a = b = c ---> ";
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  a = 0;
  b = 1;
  c = 2;

  (a = b) = c;
  std::cout << "(a = b) = c ---> ";
  std::cout << "a = " << a << "; b = " << b << "; c = " << c << std::endl;

  print_msg("(check_assignment_operator) ReturnRef");
  ReturnRef rr0(0), rr1(1), rr2(2);
  rr0.print();
  rr1.print();
  rr2.print();

  print_msg("rr0 = rr1 = rr2");
  rr0 = rr1 = rr2;
  rr0.print();
  rr1.print();
  rr2.print();

  rr0.set_x(0);
  rr1.set_x(1);
  rr2.set_x(2);

  print_msg("(rr0 = rr1) = rr2");
  (rr0 = rr1) = rr2;
  rr0.print();
  rr1.print();
  rr2.print();

  print_msg("(check_assignment_operator) ReturnCopy");
  ReturnCopy rc0(0), rc1(1), rc2(2);
  rc0.print();
  rc1.print();
  rc2.print();

  print_msg("rc0 = rc1 = rc2");
  rc0 = rc1 = rc2;
  rc0.print();
  rc1.print();
  rc2.print();

  rc0.set_x(0);
  rc1.set_x(1);
  rc2.set_x(2);

  print_msg("(rc0 = rc1) = rc2");
  (rc0 = rc1) = rc2;
  rc0.print();
  rc1.print();
  rc2.print();
}
