#include<iostream>
#include<memory>
#include<cstdlib>


int main () 
{
    std::unique_ptr<FILE, void(*)(std::FILE*)> ptr{std::fopen("out.txt", "w"), [] (std::FILE *fp) {std::fclose(fp);}};
}