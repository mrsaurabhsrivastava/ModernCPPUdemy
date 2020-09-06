#include<iostream>
#include<string>
#include<typeinfo>

using namespace std;
class Account
{
	std::string m_name;
	int m_accno; 
	static int s_accnogenerator;
protected: 
	float m_balance;
public: 
	Account(const std::string &xName, 
			float xBalance)
	:m_name(xName), 
	 m_balance(xBalance),
	 m_accno(++s_accnogenerator)
	{

	}

	std::string GetName() const 
	{
		return m_name;
	}

	float GetBalance() const 
	{
		return m_balance;
	}

	virtual void AccumulateInterest() 
	{

	}

	virtual void Withdraw(float xAmount)
	{
		if (xAmount <= m_balance)
			m_balance -= xAmount;
		else 
			cout<< "Insufficient Balance"<<endl;
	}

	virtual void Deposit(float xAmount)
	{
		m_balance += xAmount;
	}
	virtual float GetInterestRate() const 
	{
		return 0.0f;
	}

	void Print() const 
	{
		cout<<"Name ="<<m_name<<endl;
		cout<<"Account No ="<<m_accno<<endl;
		cout<<"Balance ="<<m_balance<<endl;
		cout<<"Interest Rate = "<<GetInterestRate()<<endl;
	}
};

int Account::s_accnogenerator = 1000;


class Savings : public Account
{
	float m_rate = 0.0f;
public: 
	Savings(const std::string &xName, float xBalance, float xRate)
	:Account(xName, xBalance),
	 m_rate(xRate)
	{

	}
	~Savings() {};

	float GetInterestRate() const 
	{
		return m_rate;
	}

	void AccumulateInterest() 
	{
		m_balance += ((m_balance * m_rate)/100); 
	}
};

class Checking : public Account 
{
	constexpr static float s_min_balance = 10;
public:
	using Account::Account; 
	
	void Withdraw(float xAmount) 
	{

		if (xAmount <= m_balance + s_min_balance)
			m_balance -= xAmount;
		else 
			cout<<"Insufficient Funds"<<endl;
	}
};

void Transcact(Account *pAccout)
{
	pAccout->Print();
	pAccout->Deposit(100);
	pAccout->AccumulateInterest();
	pAccout->Print();
	
}
int main () 
{
	Account acc("Saurabh Srivastava", 1000);
	

	Savings sacc("Saaruni", 100, 5);


	Checking cacc("John", 100);
	
	Transcact(&sacc);
	cout<<endl;
	float i {0};
	const std::type_info &tid = typeid(&sacc);
	if (typeid(Savings) == tid)
	{
		cout<<"I am here"<<endl;
	}
	std::cout<<tid.name()<<endl;

}