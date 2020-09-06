#include<iostream>
#include<list>
#include<thread>
#include<mutex>
#include<chrono>

std::list<int> gData;
constexpr int gDataSize=1000;
std::mutex m;

class mylock
{
    private: 
    std::mutex m;
    public: 
    void lock() 
    {
        std::cout<<__PRETTY_FUNCTION__<<" "<<std::this_thread::get_id()<<std::endl;
        m.lock();
    }
    void unlock()
    {
        std::cout<<__PRETTY_FUNCTION__<<" "<<std::this_thread::get_id()<<std::endl;
        m.unlock();
    }
};

mylock mm;

void Download()
{
    for(int i = 0; i < gDataSize; i++)
    {
        //std::lock_guard<std::mutex>(m);
        std::lock_guard<mylock> lck (mm);
        gData.push_back(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void Download2()
{
    for(int i = 0; i < gDataSize; i++)
    {
        //std::lock_guard<std::mutex> lck (m);
        std::lock_guard<mylock> lck (mm);
        gData.push_back(i);
    }
}

int main () 
{
    std::thread th(Download);
    std::thread th2(Download2);
    th.join();
    th2.join();
    std::cout<<gData.size()<<std::endl;
    std::cout<<std::thread::hardware_concurrency()<<std::endl;
}