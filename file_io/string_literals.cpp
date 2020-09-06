#include<iostream>
#include<string>
using namespace std;

int main ()
{
    //std::string lFileName {"C:\temp\newFile.txt"};
    std::string lFileName {R"(C:\temp\newFile.txt)"};
    cout<<lFileName<<endl;

    //std::string lStr {R"(Thi is new feawture in c++ "(c++11)")"};
    std::string lStr {R"MSG(Thi is new feawture in c++ "(c++11)")MSG"};
    cout<<lStr<<endl;
}