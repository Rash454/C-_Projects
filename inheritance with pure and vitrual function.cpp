#include<iostream.h>
class Person{
	protected:
	char name[20];
	int ssn;
	public:
	Person(char n[] , int s){
		strcpy(name,n);
		ssn=s;
		
	}
	virtual void print(){
	cout<<"inside const of person\n";
	}
	};
	class Employee : public Person{
	protected:	
    double salary;
    public:
    Employee(char n[] , int s, double sal ):Person(n,s){
	salary=sal;}
    virtual double calculateSalary()=0;
	
	};
	
	class FullTE:public Employee{
	public:
	FullTE(char n[] , int s, double sal):Employee(n,s,sal){
	}
	void print(){
		cout<<"inside const of FullTE\n";
	}
		double calculateSalary(){
			return salary;
		}
	
	
	};
	
	class PartTE:public Employee{
		int hrs,rate;
	public:
	PartTE(char n[] , int s, int h,int r):Employee(n,s,h*r){
		hrs=h;
		rate=r;
	}
	
	};

	main(){
	Person *p;
	p=new FullTE("Ali",89,543);
	p->print();
	Employee *p2;
	p2= new FullTE("Ahmad",89,5150.2);
	cout<<p2->calculateSalary()<<endl;
	}