#include <iostream>
using namespace std;

//  Work arr[] = {} 
int main () 
{
	//int arr[] = {1,2,3,4,5};
	char arr[] = "SSSSS";

	cout<<arr<<endl;
	for (int i=0; i < 5; i++)
		cout<<arr[i];

	cout<<endl;
	for (auto x:arr)
		cout<<x<<" ";

	cout<<endl;

	for (auto &x:arr)
	{
		cout<<x<<" ";
		x = 'm';
	}

	cout<<endl;
	for (auto x:arr)
		cout<<x<<" ";

	cout<<endl;
	for (const auto &x:arr)
	{
		cout<<x<<" ";
		
	}
	
	cout<<endl;
	cout<<endl;
	
	int *m = new int[5] {1,2,3,4,5};
	/*
	for (auto v : m)
	{
		cout<<v<<"--";
	}
	*/
 }