#include<iostream>
#include<list>
#include<thread>
#include<future>

std::list<int> gData;
constexpr int gDataSize=20000000;

int Download()
{
    std::cout<<"Download Started"<<std::endl;
    for(int i = 0; i < gDataSize; i++)
        gData.push_back(i);
    std::cout<<"Download finished"<<std::endl;
    return 10;
}

int main () 
{
    std::future<int> f = std::async(Download);
    std::cout<<"User can give another operation"<<std::endl;
    std::cout<<f.get()<<std::endl;
}