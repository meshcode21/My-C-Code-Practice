#include<iostream>
using namespace std;

class Person{
	int age; string name;
	public: 
		Person(int a,string n): age(a),name(n){}
		void operator <(Person p){ //operator overloaded to  compare age.
			if(age<p.age) cout<<name<<" is younger then "<<p.name<<endl;
			else cout<<p.name<<" is younger then "<<name<<endl;
		}
		void display(){
			cout<<"Name = "<<name<<"\nAge = "<<age<<endl;
		}
};
int main(){
	Person p1(19,"Mahesh"),p2(20,"Prashant");
	cout<<"================"<<endl;
	p1.display();
	cout<<"================"<<endl;
	p2.display();
	cout<<"================"<<endl;
	p1<p2;
	
	return 0;
}
