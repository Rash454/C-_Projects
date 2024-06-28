#include<iostream.h>
class Person{
	protected:
	char name[20];
	int ssn;
	char adders[50];
	friend void print();
	public:
	Person(char n[] , int s, char adders[]){
		strcpy(name,n);
		ssn=s;
     strcpy(this->adders,adders);
		cout<<"inside const of person\n";	
	}
	char *getName(){
		return name;
	}
	static int passingGrade;
	void setName(char *name){
		strcpy(this->name,name);
	}
	};
	int Person::passingGrade=60;
	void print(){
		cout<<"Friend function"<<endl;
	 Person obj("Ali",728,"Jenin");
	 obj.ssn=90;
	}
	class Student : public Person{
		
    double gpa;
    public:
    Student(double g ,char n[] , int s, char addr[] ):Person(n,s,addr){
	gpa=g;
		cout<<"inside const of student\n";	
	}
	};

	main(){
	Person s1( "Ali ", 934 ,"Nablus");Person s2( "Adnan ", 934 ,"Jenin");	
	s1.passingGrade=50;
	cout<<s1.passingGrade<<endl;
//	s1.setName("Ahmad");
//	cout<<s1.getName()<<endl;
	}