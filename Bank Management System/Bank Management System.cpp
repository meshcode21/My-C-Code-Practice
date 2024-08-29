#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;


class BankAccount{
	int accountNumber;
	char accountType;
	double balance;
	char name[50];
	int age;
	char gender;
	char address[50];
	
public:
	void setData(int accNo){
		accountNumber = accNo;
		cout<<"\tNew account number is: "<<accNo<<endl<<endl; 
		
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
		else if (gender == 'o') gen = "Other";
		else gen = "-----";
		
		cout<<"\t"<<accountNumber<<"\t"<<name<<"\t\t"<<age<<"\t\t"<<gen<<"\t\t"<<address<<"\t\t"<<accType<<"\t\t"<<balance<<endl;
//		cout<<"\t"<<accountNumber<<" \t"<<age<<" \t"<<gender<<" \t"<<accountType<<" \t"<<balance<<endl;
	}
	int getAccNo(){
		return accountNumber;
	}
};

void header(){
	system("cls");
	cout<<"###############################################"<<endl;
	cout<<"#                                             #"<<endl;
	cout<<"#     Welcome to Bank Management System       #"<<endl;
	cout<<"#                                             #"<<endl;
	cout<<"###############################################"<<endl<<endl;
}
char dashboard(){
	char choice;	
	
	header();
	cout<<"\t1. Create New Account"<<endl;
	cout<<"\t2. Withdraw Amount"<<endl;
	cout<<"\t3. Add Amount"<<endl;
	cout<<"\t4. Display Records"<<endl;
	cout<<"\t5. Exit"<<endl;	
	cout<<"\t\nEnter your choice:"; cin>>choice;
	return choice;
}

void createAccount(char file[]){
	ofstream f(file,ios::app);
	header();
	BankAccount acc;
	int accNo;
	
	fstream f1(file);
	if(!f1.seekg(-sizeof(acc),ios::end)) accNo = 100;
	else{
		f1.read((char*)&acc,sizeof(acc));
		accNo = 1 + acc.getAccNo();
	}
	f1.clear();
	
//	f.seekg(0,ios::end);
	acc.setData(accNo);
	if(f.write((char*)&acc,sizeof(acc)) == 0) cout<<"\n\tError while writing data..."<<endl;
	else cout<<"\n\tNew Account created successfully..."<<endl;
	getch();
}

void displayAccounts(char file[]){
	ifstream f(file);
	header();
	BankAccount acc;
	
	cout<<"\tAccNo.\tAccount Holder Name\t\tAge\t\tGender\t\tAddress\t\tAccount type\t\tCurrent Balance"<<endl;
	
//	f.open(file);
	f.seekg(0,ios::beg);
	f.read((char*)&acc,sizeof(acc));
		acc.getData();
	
	f.close();
	getch();
}

void End(){
	header();
	cout<<"\tThankyou For your Time. !!!!!"<<endl;
}

int main(){
	char filestream[] = "accounts.txt";
	
	fstream file(filestream, ios::out);
	if(!file.is_open()){
		cout<<"something is wrong in file opening...!!";
		exit(1);
	}
	file.close();
	
	char choice;
	do{
		choice = dashboard();
		switch(choice){
			case '1':
				createAccount(filestream);
			break;
			case '2':
	//			withdrawAmount();
			break;
			case '3': 
	//			addAmount();
			break;
			case '4': 
				displayAccounts(filestream);
			break;
			case '5': 
				End();
			break;
			default:
				cout<<"Invalid choice !!!!"; getch();
		}
	}while(choice != '5');
	
	file.close();
	
	return 0;	
}
