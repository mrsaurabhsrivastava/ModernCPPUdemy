#include<iostream>
using namespace std;

enum class eColor {RED, GREEN, BLUE};


enum class eTrafficLight : char {RED='c', GREEN, YELLOW};

int main () 
{
	int x = static_cast<int>(eColor::RED);
	char s = static_cast<char>(eTrafficLight::GREEN);
	cout<<x<<" "<<s<<endl;
}