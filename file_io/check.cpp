#include<iostream>
#include<fstream>
#include<string>

int main () 
{
    std::string path {R"(path\dir1\dir2\file.cfg)"};
    std::ifstream  DirLuaExec(path);
}