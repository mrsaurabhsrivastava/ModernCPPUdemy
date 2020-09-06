#include<iostream>


void Alloc() 
{
    // int *p = static_cast<int*>(malloc(sizeof(int)));
    // if (p!= nullptr)
    if (int *p = static_cast<int*> (malloc(sizeof(int))); p == nullptr)
    {
        std::cout<<" i am here"<<std::endl;
        *p = 50;
        free(p);
    }
    else if (int j = 0; j == 0)
    {
        std::cout<<" i am ere nopw"<<std::endl;
    }
    else 
    {
        std::cout<<" i am here else"<<std::endl;
        *p = 50;
        free(p);
    }
}
int main () 
{
    Alloc();
}