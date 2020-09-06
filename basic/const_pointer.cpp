#include<iostream>
using namespace std;

int main () 
{
	const int CHUNK_SIZE = 512;
	const int *ptr = &CHUNK_SIZE;	
	int x = 10;
	ptr = &x;
	//*ptr is constant, ptr is not
	const int *const ptr1 = nullptr;
	// ptr1 is constant pointer
}