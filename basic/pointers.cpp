#include<iostream>
using namespace std;

// NULL is macro in c and pre-c++1 
// NULL is defined a 0 in most compiler
// C++11 introduced a new type of null called nullptr
// nullptr is type safe
// always use nullptr 

int main () 
{
	int x = 10;
	cout<<&x<<endl;

	int *p = &x;
	cout<<p<<endl;

	int **q = &p;
	cout<<q<<endl;
	cout<<*q<<endl;

	void *ptr = nullptr;
	cout<<ptr<<endl;

	int *ptr1 = nullptr;
	//cout<<*ptr1<<endl; this is an error
}