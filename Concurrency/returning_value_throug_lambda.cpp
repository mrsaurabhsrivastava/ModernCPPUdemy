#include<iostream>
#include<list>
#include<thread>

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
    int lValue;
    std::thread th([&] () {lValue=Download();});
    std::cout<<"User can give another operation"<<std::endl;
    th.join();
    std::cout<<lValue<<std::endl;
}