#include<iostream>
#include<future>
#include<chrono>

using namespace std::chrono_literals;

int operation(int count)
{
    std::cout<<std::this_thread::get_id()<<std::endl;
    int lSum = 0;
    for (int i = 0; i < count; i++)
    {
        std::cout<<'.'<<std::flush;
        std::this_thread::sleep_for(300ms);
        lSum += i;
    }
    return lSum;
}

int main ()
{
    int count = 10;
    std::cout<<std::this_thread::get_id()<<std::endl;
    std::future<int> f = std::async(std::launch::async, operation, count);
    std::this_thread::sleep_for(1s);
    std::cout<<"I am here"<<std::endl;
    if (f.valid())
    {
        std::cout<<f.get()<<std::endl;
    } 
}