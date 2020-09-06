#include<iostream>
#include<list>
#include<thread>
#include<string>

class String
{
    private: 
    std::string dStr;

    public: 
    String(const std::string &xStr)
    :dStr(xStr)
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
    String(const String &x)
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
        dStr = x.dStr;
    }
    String & operator= (const String &x)
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
        dStr = x.dStr;
    }

    std::string mGetStr() const {return dStr;}
    ~String() 
    {
        std::cout<<__PRETTY_FUNCTION__<<std::endl;
    }
};

std::list<int> gData;
constexpr int gDataSize=20000000;

void Download(const String& x)
{
    // std::cout<<"Download Started for file : "<<x.mGetStr()<<std::endl;
    for(int i = 0; i < gDataSize; i++)
        gData.push_back(i);
    // std::cout<<"Download finished"<<std::endl;
}

int main () 
{
    String s("abc.mp4");
    // std::cout<<"User operation sarted"<<std::endl;
    //std::thread th(Download, s);
    std::thread th([&] () {Download(s);});
    // th.detach();
    //Download();
    // std::cout<<"User can give another operation"<<std::endl;
    // std::cout<<std::boolalpha<<th.joinable()<<std::endl;
    if (th.joinable())
    {
        th.join();
    }
    //system("sleep 10");
}