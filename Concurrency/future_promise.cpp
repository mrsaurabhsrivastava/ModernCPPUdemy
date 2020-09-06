#include<iostream>
#include<future>

using namespace std::chrono_literals;

void Op(std::promise<int> &data)
{
    std::future<int> f = data.get_future();
    std::cout<<"Waiting for count"<<std::endl;
    int count = f.get();
    std::cout<<"Got count"<<std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout<<'.'<<std::flush;
        std::this_thread::sleep_for(300ms);
    }
}
int main() 
{
    std::promise<int> p;
    std::future<void> f = std::async(std::launch::async, Op, std::ref(p));
    std::this_thread::sleep_for(3s);
    // p.set_value(10);
    p.set_value_at_thread_exit(10);
    if (f.valid())
    {
        //f.get();
    }
}