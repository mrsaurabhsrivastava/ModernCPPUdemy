#include<iostream>
using namespace std;

int main () 
{
	// Advantage of new over malloc 
	// that it can be initialized as when it is allocated 
	// New can initialize object, malloc and calloc can not do that
	int *p = new int(5);
	int *q = new int [10] ();
	delete [] q;
}