#include<iostream>

using namespace std;

constexpr int GetNumber() 
{
	return 42;
}

constexpr int GetNum(int i)
{
	if (i>10)
		return 0;
	else 
		return 10;
}

constexpr int Add(int x, int y)
{
	return x+y;
}
int main ()
{
	int z = 8;
	const int x = Add(5,6);
	//constexpr int y = Add(z,7);
}