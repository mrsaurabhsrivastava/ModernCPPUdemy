#include<iostream>
#include<fstream>
#include<string>
#include<experimental/filesystem>

namespace filesystem = std::experimental::filesystem;
int main () 
{
    filesystem::path source (filesystem::current_path());
    std::cout<<source.c_str()<<std::endl;
    source /= "copy_utility.cpp";
    filesystem::path dest(filesystem::current_path());
    dest /= "copy.cpp";

    std::ifstream input{source};
    if (!input)
    {
        std::cout<<"Source file not found"<<std::endl;
        return -1;
    }

    std::ofstream output{dest};
    std::string line;

    while(!std::getline(input, line).eof())
    {
        output<<line<<std::endl;
    }
    input.close();
    output.close();
    return 0;
}

