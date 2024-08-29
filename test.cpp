#include<iostream>
using namespace std;

class A{
	public:
		A(){
			cout<<"Constructor called"<<endl;
		}
		~A(){
			cout<<"Distructor called"<<endl;
		}
};

void call(){
	A a;
}

int main(){
	call();
	A a;
	cout<<"hello my friend..."<<endl;
	
	return 0;
}
