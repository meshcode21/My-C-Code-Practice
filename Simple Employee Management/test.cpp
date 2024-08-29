#include<iostream>
using namespace std;

class Persion{
	protected:
		string name;
		int age;
		char gender;
		string adddress;
};

class BankAccount:public Persion{
	int accountNumber;
	int accountType;
	
	public:
	void setData(){
		cout<<"\tEnter new account number:"; cin>>accountNumber;
		again:
		cout<<"\tAccount type [1.current/2.saving]:";
		cin>>accountType;
		if(accountType != 1 && accountType != 2){
			cout<<"Invalid input !!"<<endl;
			goto again;
		}
	}
	void getData(){
		cout<<"\tAccNo: "<<accountNumber;
		if(accountType == 1) cout<<" AccType: Current"<<endl;
		else if(accountType == 2) cout<<" AccType: Saving"<<endl;
	}
};

int main(){
	 FILE *file;
	 file = fopen("")
}
