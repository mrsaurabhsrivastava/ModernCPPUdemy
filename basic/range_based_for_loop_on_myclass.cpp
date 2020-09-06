#include<iostream>
#include<string>
using namespace std;
class String 
{
private: 
	string s;
public: 
	String() {cout<<"Empty string constructed"<<endl;}
	String(const char* x) {
		cout<<"String constructed\n";
		s = x;}
	~String() {cout<<"String destrcuted\n";}
	String (const String& x)
	{
		cout<<"String Copied"<<endl;
		s = x.s;
	}

	void operator=(const String& x)
	{
		cout<<"String operator ="<<endl;
		s = x.s;
	}

	String (String&& x)
	{
		s = std::move(x.s);
	}

	void mPrint() 
	{
		cout<<s<<endl;
	}
	/*ostream& operator<<(ostream& os, const String& obj)
	{
		os<<s;
		return os;
	}
	*/
};

template<typename T, size_t N> 
class Vector
{
private: 
	T mArray[N];
	int mCurrIndex = 0;
public: 
	size_t mGetSize() {return N;}
	void mPush(const T& x)
	{
		mArray[mCurrIndex++] = x;
	}

	void mPush(T&& x)
	{
		mArray[mCurrIndex++] = x;
	}
	void mPrint() 
	{
		for (int i = 0; i < N; i++)
		{
			mArray[i].mPrint();
		}
		//for (const auto& v:mArray)
		//	cout<<v<<endl;
	}
	inline T* begin() noexcept {return &mArray[0];}
	inline T* end() noexcept {return &mArray[N];}
	inline bool operator!= (const T& lhs, const T& rhs)
	{

	} 
};

int main ()
{
	Vector<String, 3> lStringVector;
	String S("Saurabh");
	lStringVector.mPush(std::move(S));
	lStringVector.mPush("Srivastava");
	lStringVector.mPush("C++");
	//lStringVector.mPrint();
	//cout<<S<<endl;
	for (auto v:lStringVector)
	{
		v.mPrint();
	}
	
}