#include<iostream>
#include<string>
using namespace std;


string toUpper(const std::string &xStr)
{
	string lResult;
	for (auto c:xStr)
	{
		if (c >= 'a' && c <= 'z')
		{
			lResult += (c - ' '); // ' ' == 32
		}
		else 
			lResult += c;
	}
	return lResult;
}

string toLower(const std::string &xStr)
{
	string lResult;
	for (auto c:xStr)
	{
		if (c >= 'A' && c <= 'Z')
		{
			lResult += (c + ' '); // ' ' == 32
		}
		else 
			lResult += c;
	}
	return lResult;
}

int main () 
{
	string s = "Saurabh Srivastava";
	cout<<toUpper(s)<<endl;
}