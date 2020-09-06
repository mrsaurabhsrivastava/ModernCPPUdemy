#include<iostream>
using namespace std;
// Reference are alternative name for a variable

void Add(int a, int b, int &result)
{
	result = a+b;
}

void Factorial(int a, int &result)
{
	result = 1;
	for (int i = 1; i <=result; i++)
		result *= i;
}

void Swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}
int main () 
{
	int i = 10;
	// i is referent
	// ref is reference 	
	int &ref = i;
	cout<<i<<" "<<ref<<endl;
	i = 101;
	cout<<i<<" "<<ref<<endl;
	ref = 1010;
	cout<<i<<" "<<ref<<endl;
	cout<<&i<<" "<<&ref<<endl;
	int j = 20;
	ref = j;
	cout<<i<<" "<<ref<<endl;
}