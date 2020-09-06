#include<iostream>
#include<memory>
#include<cstdio>

int main () 
{
    using namespace std;
    std::unique_ptr<std::FILE, void(*)(std::FILE*)> fp(std::fopen("my.txt", "w"), [] (FILE* f) {fclose(f);});
    
}