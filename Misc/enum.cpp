#include<iostream>
using namespace std;

enum eColor {RED, YELLOW};

void fillColor(eColor xColor)
{

}

void fillColorInt(int xColor)
{

}
int main () 
{
	fillColorInt(RED);
	int x = YELLOW;
	cout<<x<<endl;

	eColor y = static_cast<eColor>(0);

}