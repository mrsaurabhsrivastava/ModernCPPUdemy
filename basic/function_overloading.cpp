#include<iostream>
using namespace std;

// const qualifier also participate in function verloading
// Return type not considered
// name mangeling generate unique name
// extern "C" can disable name mangeling
// by extern "C" we can call C++ function from C 

void gPrint(int *a)
{
	cout<<"without const called"<<endl;
	cout<<*a<<endl;
}

void gPrint(const int *a)
{
	cout<<"with const called"<<endl;
	cout<<*a<<endl;
}
int main ()
{
	int a = 99;
	const int b = 101;
	gPrint(&a);
	gPrint(&b);
}