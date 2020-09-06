#include<iostream>
using namespace std;

// ++i is lValue
// function return references return lvalue 
// function return value return rvalue

int mChange(int x)
{
	return x+1;
}

int& mValue(int &x)
{
	x *= x;
	return x;
}

void mPrint(int &x)
{
	cout<<"Print (int &x)" <<endl;
}

void mPrint (int &&x)
{
	cout<<"mPrint (int &&x)"<<endl;
}


void mPrint( const int &x)
{
	cout<<"mPrint(const int &x)"<<endl;
}
int main () 
{
	int i = 0;
	++i = 19; // ++i returns a lValue reference
	//cout<<i<<endl;
	mValue(i) = 10; // mValue returns a lValue reference
	//cout<<i;
	int &&r1 = 10;
	int &&r2 = mChange(10);
	int &ref = mValue(i);
	//
	// A lvalue reference may bind to a temporary 
	// if reference is constant
	const int &ref2 = 3;

	int x = 10;
 	mPrint(x);
 	mPrint(3); // First priority to rvalue reference 
 			   // if function not found than it will bind 
 	           // to const lvalue reference 
}