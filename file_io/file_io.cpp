#include<iostream>
#include<fstream>
#include<string>

void Write() {
    std::ofstream out("data.txt");
    out<<"Hello World"<<std::endl;
    out<<10<<std::endl;
    out.close();
}

void Read() 
{
    std::ifstream in("data.txt"); // we can also use open
    //std::ifstream in;
    //in.open("data.txt");
    
    if (!in.is_open())
    {
        std::cout<<"Could not open file"<<std::endl;
        return;
    }

    std::string msg;
    std::getline(in, msg);
    int value{};
    in>>value;
    std::cout<<std::boolalpha<<in.fail()<<std::endl;
    std::cout<<std::boolalpha<<in.eof()<<std::endl;
    in>>value;
    std::cout<<std::boolalpha<<in.fail()<<std::endl;
    std::cout<<std::boolalpha<<in.eof()<<std::endl;
    in.clear();
    std::cout<<std::boolalpha<<in.fail()<<std::endl;
    std::cout<<std::boolalpha<<in.eof()<<std::endl;
    in.close();
    std::cout<<"Msg "<<msg<<" Value "<<value<<std::endl;
}

int main () 
{
    Write();
    Read();
}