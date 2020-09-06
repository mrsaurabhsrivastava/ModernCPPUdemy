#include<iostream>
#include<string>
#include<vector>

using namespace std;
enum class Case {SENSITIVE, INSENSTIVE};

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


std::vector<int> FindAll(const std::string &xTarget, 
						 const std::string &xParren,
						 Case xSearchCase=Case::INSENSTIVE,
						 size_t xOffset=0)
{
	string lTarget = xTarget;
	string lPattern = xParren;
	std::vector<int> lResult;
	if (xSearchCase == Case::INSENSTIVE)
	{
		lTarget = toLower(lTarget);
		lPattern = toLower(lPattern);
	}

	size_t lFindPos = lTarget.find(lPattern, xOffset);
	size_t lOffset = 0;
	while(lFindPos != std::string::npos)
	{
		lResult.push_back(lFindPos+lOffset);
		lOffset += (lFindPos+lPattern.size());
		lTarget = lTarget.substr(lFindPos+lPattern.size());
		lFindPos = lTarget.find(lPattern);
	}
	return lResult;
}

int main () 
{
	string s = "saurabh sri suhasini sri saaruni sri";
	string pat = "S";
	std::vector<int> v = FindAll(s, pat, Case::INSENSTIVE, 0);
	for (auto e : v)
		cout<<e<<" ";
	cout<<endl;
}