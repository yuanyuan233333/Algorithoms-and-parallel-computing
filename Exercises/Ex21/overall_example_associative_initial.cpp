#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>


using std::map;
using std::unordered_map;
using std::pair;
using std::string;

using std::cout;
using std::endl;


void print(const map<int, string> & m);

void print(const unordered_map<int, string> & um);


int main()
{

	// Student ID and name  
	map<int, string> m;

	unordered_map<int, string>  um;
	
	// all containers are empty
	// let's store 
	//  1, "Elem 1" 
	//  2, "Elem 2"
	//  4, "Elem 4"

	// Let's copy m to um


	// writing  elements to cout (read only)
	cout << "Print m" << endl;
	print(m);

	cout << "Print um" << endl;
	print(um);


	// let's try to insert again 4
	cout << "Trying to insert 4 again" << endl;


	cout << "Print m" << endl;
	print(m);

	cout << "Print um" << endl;
	print(um);

	// Let's change elem 4!
	cout << "Changing 4" << endl;

	cout << "Print m" << endl;
	print(m);

	cout << "Print um" << endl;
	print(um);
	


	// Let's look for 1 and print
	if (/*  */)	{
		cout << "Yeah!  1 is here and it's element is: " << m[1] << endl;
	}

	if (/*  */)	{
		cout << "Yeah!  1 is here and it's element is: "<< um[1] << endl;
	}

	// Let's look for 5 and print 
	if (/*  */)	{
		cout << "Unfortunately 5 is not here "<< endl;
	}

	if (/*  */)	{
		cout << "Unfortunately 5 is not here "<< endl;
	}

	// Try to access elem 5!  We are inserting empty string

	cout << "Print m" << endl;
	print(m);

	cout << "Print um" << endl;
	print(um);

	// Try to access elem 6!  This will raise an exception


	// delete all elements


	// All um are deleted through destructors ;)!!!

	return 0;
}	


void print(const map<int, string> & m){

}

// same for unoredered_map and not very different from, e.g., vectors!
void print(const unordered_map<int, string> & um){

}





