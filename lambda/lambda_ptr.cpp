#include<iostream>

int main () 
{

    auto f = [] () {};
    std::cout<<typeid(f).name()<<std::endl;

    auto b = &f;
    std::cout<<typeid(b).name()<<std::endl;


}