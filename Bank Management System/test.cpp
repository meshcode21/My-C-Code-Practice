#include <iostream>
#include <fstream>
#include<string.h>

using namespace std;

class Complex_Number{
	double a,b;
public:
	int accountNumber;
	char accountType;
	double balance;
	char name[50];
	int age;
	char gender;
	char address[50];
	
	void setData(int accNo){
		accountNumber = accNo;
		cout<<"\tNew account number is: "<<accountNumber<<endl<<endl; 
		
		againType:
		cout<<"\tAccount type [c/s]:";
		cin>>accountType;
		if(accountType != 'c' && accountType != 's'){
			cout<<"\t\t!! Invalid input !!"<<endl;
			goto againType;
		}
		
		cout<<"\n\tEnter Basic details of new Account Holder"<<endl;
		cout<<"\tName: "; cin>>name;
		cout<<"\tAge: "; cin>>age;
	againGender:
		cout<<"\tGender[m/f/o]:"; cin>>gender;
		if(gender!='m' && gender!='f' && gender!='o'){
			cout<<"\t\t!! Invalid input !!"<<endl;
			goto againGender;
		}
		cout<<"\tAddress: "; cin>>address;
		cout<<"\n\tEnter Opening Balance: Rs."; cin>>balance;
	}
	
	void getData(){
		string accType;
		string gen;
		if(accountType == 'c') accType = "Current";
		else if(accountType == 's') accType = "Saving";
		else accType = "----";
		
		if(gender == 'm') gen = "Male";
		else if(gender == 'f') gen = "Female";
		else gen = "Other";
		
		cout<<"\t"<<accountNumber<<" \t"<<name<<" \t"<<age<<" \t"<<gen<<" \t"<<address<<" \t"<<accType<<" \t"<<balance<<endl;
//		cout<<"\t"<<accountNumber<<" \t"<<age<<" \t"<<gender<<" \t"<<accountType<<" \t"<<balance<<endl;
	}
	int getAccNo(){
		return accountNumber;
	}
};
int main(){
	ifstream file;
	file.open("accounts.txt");
	if(!file.is_open()){
		cout<<"Error while opening file..";
		return 1;
	}

	BankAccount e1;
//	BankAccount acc;
	int accNo = 100;
	
//	if(!file.seekg(-sizeof(acc),ios::beg)) accNo = 100;
//	else{
//		file.read((char*)&acc,sizeof(acc));
//		accNo = 1 + acc.getAccNo();
//	}
	
//	e1.setData(accNo);
	
//	cout<<file.write((char*)&e1,(int)sizeof(BankAccount));
	file.seekg(0,ios::beg);
	cout<<file.read((char*)&e1,sizeof(e1));
		e1.getData();
	
	
	file.close();
    return 0;
}
