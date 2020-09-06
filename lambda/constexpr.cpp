#include<iostream>

int main () 
{
    auto f = [] (int x, int y) 
    {
        return x+y;
    };

    int z = f(3,4);
}