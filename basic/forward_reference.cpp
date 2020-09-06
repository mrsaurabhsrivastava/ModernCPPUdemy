#include<iostream>

using namespace std;

void foo(int &&i)
{
	cout<<i<<endl;
}

template <typename T>
void bar(T &&i)
{
	cout<<i<<endl;
}
int main () 
{
	foo(1); // worked 

	int x = 10;
	//foo(x); // Didn't worked

	bar(9);
	bar(x); // Worked WOW
}