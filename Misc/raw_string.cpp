#include<iostream>
#include<cstring>
using namespace std;

const char* combine(const char *xFirstName, const char *xLastName)
{
	//char lFullName[20];
	//char *lFullName = new char[strlen(xFirstName) + strlen(xLastName) + 1];
	char lFullName[strlen(xFirstName) + strlen(xLastName) + 1];
	strcpy(lFullName, xFirstName);
	strcat(lFullName, xLastName);
	cout<<lFullName<<endl;
	cout<<strlen(lFullName)<<endl;
}

int main () 
{
	char lFirstName[10];
	char lLastName[10];
	std::cin.getline(lFirstName, 10);
	std::cin.getline(lLastName, 10);

	const char *lFullName  = combine(lFirstName, lLastName);
	cout<<lFullName<<endl;
	//delete [] lFullName;
}