#include<iostream>
#include<memory>
#include<fstream>
using namespace std;
/*
int main ( )
{
	string fileName = "num.txt";
	ifstream inFile;
	inFile.open( fileName,std::ifstream::in );
	if ( inFile.is_open() ) {
    	int size = 0;
    	string line;
    	while( getline(inFile, line)) 
    	{

         	size++;
    	}
    	int* array = new int [ size ];
    	inFile.clear();
    	inFile.seekg(0, std::ios::beg);
    	while ( getline( inFile, line )) {
         //....
    		cout<<line<<endl;
    	}
    }
}

*/
int main ( )
{
	string fileName = "num.txt";
	ifstream inFile;
	inFile.open( fileName,std::ifstream::in );
	if ( inFile.is_open() ) {
    	int size = 0;
    	std::string line;
    	std::vector<int> lines;
    	while( getline(inFile, line)) 
    	{
         	lines.push_back(std::strtline);
    	}
    	int* array = new int [ size ];
    	inFile.clear();
    	inFile.seekg(0, std::ios::beg);
    	while ( getline( inFile, line )) {
         //....
    		cout<<line<<endl;
    	}
    }
}
