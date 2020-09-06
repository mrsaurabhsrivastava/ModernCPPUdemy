#include<iostream>
using namespace std;

void Swap(int *x, int *y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void Swap(int &x, int &y)
{
	int tmp = x;
	x = y;
	y = tmp;
}

void Print(int *ptr)
{
	if (ptr)
		cout<<*ptr<<endl;
}

void Print(int &ref)
{
	cout<<ref<<endl;
}
int main () 
{
	int x = 5;
	Print(nullptr);
	Print(&x);
	Print(x);
	/*
	int a = 5, b = 10;
	Swap(a,b);
	cout<<"a = "<<a<<" b = "<<b<<endl;
	*/
}