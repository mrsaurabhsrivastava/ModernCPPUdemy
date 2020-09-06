#include<iostream>
using namespace std;

// if you write function defination in class defination itself in header file
// compile automatically try to make function inline
inline int Square(int x)
{
	return x*x;
}
int main () 
{
	int i = 6;
	int result = Square(i);
	cout<<result;
}