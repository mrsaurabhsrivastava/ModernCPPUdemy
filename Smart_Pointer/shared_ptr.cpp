#include<iostream>
#include<memory>
using namespace std;


class Project
{

};

class Employee
{
	shared_ptr<Project> m_project;
public: 
	void SetProject(shared_ptr<Project> p)
	{
		m_project = p;
	}

	Project* GetProject() const 
	{
		return m_project.get();
	}

};

Employee* AssignProject ()
{
	shared_ptr<Project> p = make_shared<Project>();
	Employee *e1 = new Employee();
	cout<<p.use_count()<<endl;
	e1->SetProject(p);
	cout<<p.use_count()<<endl;
	return e1;
}
int main () 
{
	Employee *e = AssignProject();
}