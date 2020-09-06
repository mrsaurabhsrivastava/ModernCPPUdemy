#include <iostream>

using namespace std;

auto Sum(int x, int y)
{
	return x+y;
}

// auto initialization alwas need initializer
int main () 
{
	auto i{10};
	auto j {11+i};
	cout<<j<<endl;
	auto k = i+j;
	cout<<k<<endl;
	auto l = k + 4.3f; // largest size variable is considered
	cout<<l<<endl;

	auto reslult = Sum(i,j);

	const int x = 10;
	auto y=x; // y will not constant
	const auto y1 = x; // y will be constant
	auto &y2 = x; // here y2 is const ref 
	
	auto list = {1,2,3,4}; // this is initializer list
	auto m{1}; // this is an int
}