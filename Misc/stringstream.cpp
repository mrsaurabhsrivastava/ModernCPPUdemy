#include<iostream>
#include<sstream>
using namespace std;

int main () 
{
	std::stringstream s; // manages an internal string buffer 
	s << "I am saurabh" << "Age is " << 32;
	cout<<s.str()<<endl;// 

	string s1 = std::to_string(5); // c++11 to_string internally use string stream

	s.str("ok");
	cout<<s.str()<<endl; 
	std::istringstream is; // only input (read is permitted)
	std::ostringstream os; // only ourout (write is permitted)

	string str = "1 3 4 5";
	s.str(str);
	//while(!s.fail()) // fail when attempt to read when last number is extracted, it will print last number twice
	int a;
	while (s>>a) // string operator has bool operator overloaded which get failbit , s>>a return s 
	{
		cout<<a<<endl;
	}
}