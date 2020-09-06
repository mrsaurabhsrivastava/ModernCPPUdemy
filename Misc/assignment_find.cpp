#include<iostream>
#include<string>
using namespace std;

enum class Case {SENSITIVE, INSENSITIVE};

string toUpper(const std::string &xStr)
{
	string lResult;
	for (auto c:xStr)
	{
		if (c >= 'a' && c <= 'z')
		{
			lResult += (c - ' '); // ' ' == 32
		}
		else 
			lResult += c;
	}
	return lResult;
}

string toLower(const std::string &xStr)
{
	string lResult;
	for (auto c:xStr)
	{
		if (c >= 'A' && c <= 'Z')
		{
			lResult += (c + ' '); // ' ' == 32
		}
		else 
			lResult += c;
	}
	return lResult;
}


size_t Find(const std::string &xSource, 
			const std::string &xSearchPattern, 
			Case xSearchCase=Case::INSENSITIVE, 
			size_t xOffset = 0)
{
	size_t lLocation = std::string::npos;
	if (xSearchCase == Case::SENSITIVE)
		lLocation = xSource.find(xSearchPattern, xOffset);
	else
	{
		// case insentive search 
		// convert both xSource and xSearch string in lower case
		std::string lLowerCaseSource = toLower(xSource);
		std::string lLowerCaseSearch = toLower(xSearchPattern);
		lLocation = lLowerCaseSource.find(lLowerCaseSearch, xOffset);
	}
	return lLocation;
}

int main () 
{
	std::string lString = "aaa Saurabh fadfadsf fasdfa AAA fdsaa";
	std::string lPattern = "aaa";
	cout<<Find(lString, lPattern, Case::INSENSITIVE, 1)<<endl;
}