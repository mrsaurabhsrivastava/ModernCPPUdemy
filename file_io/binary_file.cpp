#include<iostream>
#include<fstream>
#include<string>
#include<string.h>

//Binary file don't have eof char

struct record
{
    int id;
    char name[10];
};

void WriteRecord(record *p)
{
    std::ofstream binstream("record", std::ios::binary);
    binstream.write((const char*)p, sizeof(record));
}

record GetRecord()
{
    std::ifstream in("record", std::ios::binary);
    record r;
    in.read((char*)&r, sizeof(record));
    return r;
}
int main () 
{
    /*
    std::ofstream textstream{"txtdata.txt"};
    textstream<<12345678;
    std::ofstream binstream{"bindata.txt",std::ios::binary};
    int num{12345678};
    binstream.write((const char*)&num, sizeof(num));
    textstream.close();
    binstream.close();

    std::ifstream in{"bindata.txt", std::ios::binary | std::ios::in};
    int lNewNum{};
    in.read((char*)&lNewNum, sizeof(lNewNum) );
    std::cout<<"New num "<<lNewNum<<std::endl;
    */

   record r;
   r.id = 101;
   strcpy(r.name, "Saurabh");
   WriteRecord(&r);
   record r2 = GetRecord();
   std::cout<<r2.id<<r2.name<<std::endl;
}