#include<iostream>
using namespace std;

class Integer 
{
	int *dInt = nullptr;
public: 
	Integer(int xInt)  {
		dInt = new int(xInt);
		cout<<"Integer Created"<<endl;
	} 
	Integer(const Integer &xObj)
	{
		cout<<"Copy called"<<endl;
		dInt = new int(xObj.mGetInt());
	}

	Integer(Integer &&xObj)
	{
		cout<<"Move called"<<endl;
		dInt = xObj.dInt;
		xObj.dInt = nullptr;
	}

	Integer Add(const Integer& x, const Integer& b)
	{
		return Integer(x.mGetInt() + b.mGetInt());
	}
	Integer& operator=(const Integer &xObj)
	{
		cout<<"Assignment operator called"<<endl;
		*dInt = xObj.mGetInt();
		return *this;
	}

	Integer& operator=(Integer &&xObj)
	{
		cout<<"Move Assignment operator called"<<endl;
		delete dInt;
		dInt = xObj.dInt;
		xObj.dInt = nullptr;
		return *this;	
	}
	~Integer() 
	{
		cout<<"Integer destroyed"<<endl;
		delete dInt;
	}

	int mGetInt() const {return *dInt;}
};

class Product 
{
	Integer dId;
public: 
	Product(Integer&& xId)
	:dId(std::move(xId))
	{

	}
	//Product(Integer xId)
	//:dId(std::move(xId))
	//{

	//}
	//Product(const Integer &xId)
	//:dId(xId)
	//{
	//
	//}

};

int main () 
{
	Integer a(10);
	//Product P(a);
	//Product P(10+10);
	Product P(a.Add(a,10));
	Product(a);
}