#include<iostream>

[[nodiscard]] int * CreateIntArray(int xSize)
{
    return new int(xSize);
}

int main () 
{
    CreateIntArray(10);
}