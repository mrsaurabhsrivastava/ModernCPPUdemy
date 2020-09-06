#include<iostream>
#include<fstream>
#include<string>

void Write() 
{
    std::ofstream out{"test.txt"};
    if (!out)
    {
        std::cout<<"Could not open file for writing"<<std::endl;
        return;
    }

    std::string message{"C++ was invented by Bjarne"};
    for (char ch:message)
    {
        out.put(ch);

    }
    out.seekp(5);
    std::cout<<out.tellp()<<std::endl;
    out.put('#');

}

void Read() 
{
    std::ifstream in{"test.txt"};
    if (!in)
    {
        std::cout<<"Could not open file for reading"<<std::endl;
    }

    char ch{};
    in.seekg(5, std::ios::cur);
    std::cout<<"Current position of get ptr "<<in.tellg()<<std::endl;
    while (in.get(ch))
    {
        std::cout<<ch;
    }
    std::cout<<"Current position of get ptr "<<in.tellg()<<std::endl;
    in.clear();
    in.seekg(5);
    in.seekg(5);
    std::cout<<"Current position of get ptr "<<in.tellg()<<std::endl;
}

void UsingFrstream() 
{
    std::fstream stream; 
}
int main () 
{
    Write();
    Read();
}