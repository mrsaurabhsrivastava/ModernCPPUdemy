#include<iostream>
using namespace std;

// Value initializatiopn T obj{};
// Direct initialization T obj();
// Copy initialization T obj = v; // should be avoided for user defined case

// Uniform initialization 
// It forces initialization 
// You can use direct initialization for array types 
// It prevent narrowing coversion ? float->Int , int->float; Goto code
// Uniform syntex 

int main () 
{
	int i{10}; 
	std::cout<<i<<endl;

	char *p = new char[10]{'H','e','l','l','o'};
	//char *q = new char[16]{"Hello World"};
	cout<<p<<endl;
	//cout<<q<<endl;

	float f{10.5};
	int j = f; // this throws no warning/error 

	int k {f}; // It throws a warning
	std::cout<<k<<endl;;
	int l = 10;
	float f1 = l; // this throws no warning/error
	float f2{l}; // It throws a warning


	char* lCheck {};
	cout<<lCheck;

}