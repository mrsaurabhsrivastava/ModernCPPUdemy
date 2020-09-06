#include<iostream>
#include<list>
#include<thread>

std::list<int> gData;
constexpr int gDataSize=20000000;

void Download()
{
    std::cout<<"Download Started"<<std::endl;
    for(int i = 0; i < gDataSize; i++)
        gData.push_back(i);
    std::cout<<"Download finished"<<std::endl;
}

int main () 
{
    std::cout<<"User operation sarted"<<std::endl;
    std::thread th(Download);
    th.detach();
    //Download();
    std::cout<<"User can give another operation"<<std::endl;
    std::cout<<std::boolalpha<<th.joinable()<<std::endl;
    if (th.joinable())
    {
        th.join();
    }
    system("sleep 10");
}