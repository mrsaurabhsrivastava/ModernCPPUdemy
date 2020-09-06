#include<iostream>
#include<vector>
#include<string>

template <typename T>
class Printer
{
    private: 
        T *mData;
    public: 
        Printer(T *xData) : mData(xData) {}

        void mPrint() 
        {
            std::cout<<"{"<<*mData<<"}"<<std::endl;
        }

        T mGetData() 
        {
            return *mData;
        }

};

template<> 
void Printer<std::vector<int>>::mPrint()
{
    std::cout<<"{";
    for (const auto &v : *mData)
    {
        std::cout<<v;
    }
    std::cout<<"}"; 
} 

template<>
void Printer<std::vector<std::vector<int>>>::mPrint() 
{
    std::cout<<std::endl;
    std::cout<<"{"<<std::endl;
    for (const auto &v : *mData)
    {
        std::cout<<"{";
        for (const auto &vv : v)
        {
            std::cout<<vv;
        }
        std::cout<<"}";
        std::cout<<std::endl;
    }
    std::cout<<"}"<<std::endl;
}
int main() 
{
    int i = 88;
    Printer<int> p(&i);
    p.mPrint();

    std::vector<int> v {1,5,2,3,8,99};
    Printer<std::vector<int>> pp(&v);
    pp.mPrint();

    std::vector<std::vector<int>> vv = {{1,3,4,8,10,9111},
                                       {3,4,5,1,32,44}};
    Printer<std::vector<std::vector<int>>> ppp(&vv);
    ppp.mPrint();
}