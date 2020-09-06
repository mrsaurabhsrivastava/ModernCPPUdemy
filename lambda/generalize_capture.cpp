#include<iostream>
#include<fstream>
#include<memory>

int main () 
{
    int x = 0;
    double z = 2.3; 
    [y=x+z] () {
        std::cout<<y+10<<std::endl;
    } ();

    std::ofstream out{"out.txt"};
    auto write = [out = std::move(out)] (auto x) mutable {
        out<<x;
    };

    write("Saurabh\n");
    write("Srivastava\n");
    write(23);
    
    std::unique_ptr<int> lPtr = std::make_unique<int>(10);    
    [lPtr = std::move(lPtr)] () {
        std::cout<<*lPtr<<std::endl;
    } ();

    
}