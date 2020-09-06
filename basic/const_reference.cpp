#include<iostream>
using namespace std;


void Print(const int &ref)
{
	cout<<ref<<endl;
}
int main () 
{
	// int &ref = 5; No allowed
	const int &ref = 5;
	//cout<<ref<<endl;

	int i = 0;
	const int &ref1 = i;
	Print(ref1);
	Print(7);
	//cout<<i<<endl;
}