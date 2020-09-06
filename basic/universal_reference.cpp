#include<iostream>
using namespace std;

// universal reference will be either auto or templatize;
template <typename T>
void foo() 
{
	int j = 0;
	T&& ref = j;
}

int main () 
{
	int j = 10;
	auto&& i = j; // this is lvalue reference 
	auto&& k = 10; // this is lvalue reference


}