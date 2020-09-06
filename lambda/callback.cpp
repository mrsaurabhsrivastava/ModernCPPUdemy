#include<iostream>
#include<vector>
#include<string>
#include<functional>
#include<typeinfo>
using namespace std;


class Shelf
{
    std::vector<std::string> _book {"C++", "C++11", "C++14"};
    public: 
    Shelf() = default;
    template <typename fun>
    void For_Each(fun f)
    {
        for (const auto &e:_book) f(e);
    }
    using callbackFun = void (*) (const std::string &);
    void For_Each(callbackFun f)
    {
        for (const auto &e:_book) f(e);
    }
};

template<typename T> 
void gFun(T a)
{
    std::cout<<typeid(T).name()<<std::endl;
}

void gFun1(std::function<void(int)> f)
{
    f();
}

int main () 
{
    Shelf s;
    s.For_Each([](auto e){std::cout<<e<<std::endl;});
    std::function<void(const std::string& a)> f = [] (auto e) {std::cout<<e<<":"<<std::endl;};
    s.For_Each(f);

    gFun("Saurabh");
    gFun([]() {});

    gFun1([](int x){std::cout<<x<<std::endl;}
}