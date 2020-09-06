#include<iostream>
using namespace std;

void fun(auto &f)
{
    std::cout<<f()<<std::endl;
    std::cout<<f()<<std::endl;
}

int getNum() 
{
    return 10;
}
int main () 
{
    auto counter = [i = getNum()] () mutable {
        return ++i;
    };

    fun(counter);
    //auto newCounter = counter;
    std::cout<<counter()<<std::endl;
    std::cout<<counter()<<std::endl;

    //std::cout<<newCounter()<<std::endl;    
    //std::cout<<newCounter()<<std::endl;    
}

