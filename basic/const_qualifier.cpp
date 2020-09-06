#include<iostream>

//  Magic number do not communicate their meaning 
using namespace std;
int main () 
{
	const float PI{3.141f};
	float radius = 0;
	cout<<"radius = "<<endl;
	cin>>radius;
	float area = PI * radius * radius;
	float circumference = PI * 2 * radius;
	cout<<"Area is "<< area <<endl;
	cout<<"Circumference is "<<circumference<<endl;
	
}