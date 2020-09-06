#include<iostream>
using namespace std;


void Print(int count, char ch)
{
	for(int i = 0; i < count; i++)
		cout<<ch;
	cout<<endl;
}

void PrintExitMessage () 
{
	cout<<"Program Exit"<<endl;;
}
int main () 
{
	Print(5, '#');

	void (*f)(int, char) = Print; // function name is also address of funtion
	//void (*f)(int, char) = &Print;
	f(8,'*');
	(*f)(8,'%');
	atexit(&PrintExitMessage);
	cout<<"End of main"<<endl;
}