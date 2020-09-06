#include<iostream>
#include<functional>

class Employee
{

};

void Hashed() 
{
    std::hash<std::string> h;
    std::cout<<"Hash : "<<h("Hello")<<std::endl;
}

int main () 
{
    Hashed();
}