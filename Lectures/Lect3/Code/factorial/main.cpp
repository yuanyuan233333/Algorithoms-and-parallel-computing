#include <iostream>
using  std::cout;
using  std::endl;


const int MAX_N = 2;

int fact (int n);

int main (void)
{
	int fact_number;     /* factorial of a number */
	int sum = 0;

	for (int number = 0; number <= MAX_N; ++number) {
			fact_number = fact(number);
			sum = sum + fact_number;
	}

	cout << "The sum of the first " << MAX_N
		 << " numbers is " << sum << endl;

	return 0;
}

int fact (int n)
{
	int result=1;

  if (n==0 || n ==1)
    result = 1;
  else
    result = n * fact(n-1);

	return result;

}