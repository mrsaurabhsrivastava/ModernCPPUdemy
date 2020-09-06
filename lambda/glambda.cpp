#include<iostream>

using namespace std;

template<typename T>
void Print(T a)
{
    cout<<a<<endl;
}

template <typename T, typename... args> 
void Print(T a, args... manyT)
{
    cout<<a<<endl;
    Print(manyT...);
}

int main () 
{
    auto gPrintLamda = [] <typename... args> (args... manyT) { Print(manyT...);};
    gPrintLamda("Saurabh", 32);

    auto gPrLambda = [] (auto ... manyT) {Print(manyT...);};

    auto forward_lamda = [] (auto&& ... manyT) {
        Print(std::forward<decltype(manyT)>(manyT)...);
    };

    forward_lamda("Sri", "Love");
    auto gPrintLamdaForward = [] <typename... args> (args&&... manyT) { 
        Print(std::forward<args>(manyT)...);
    };

    gPrintLamdaForward("OK fine");
}