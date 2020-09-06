#include<iostream>
using namespace std;

int main () 
{
	int a = 5 , b = 3;
	float  f = static_cast<float>(a)/2;

	char* p = reinterpret_cast <char*> (&a);

	const int x = 6;
	const int *p1 = reinterpret_cast<const int*> (&x);

	//*p1 = 11;
	cout<<x<<endl;

	cout<<f<<endl;
}