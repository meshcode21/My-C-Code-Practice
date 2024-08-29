#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
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
		cin.ignore();
		cout<<"\tName: "; cin.getline(name,50);
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
		
		cout<<left;
		cout<<"| "<<setw(8)<<accountNumber<<"| "<<setw(18)<<name<<"| "<<setw(4)<<age<<"| "<<setw(8)<<gen<<"| "<<setw(13)<<address<<"| "<<setw(8)<<accType<<"| "<<setw(13)<<balance<<"|"<<endl;
	}
	int getAccNo(){
		return accountNumber;
	}
};

void header(){
	system("cls");
	cout<<"#"<<setw(86)<<setfill('#')<<"#"<<endl;
	cout<<"#"<<setw(86)<<setfill(' ')<<"#"<<endl;
	cout<<"#"<<setw(85)<<left<<"                       Welcome to Bank Management System"<<"#"<<endl;
	cout<<"#"<<setw(86)<<setfill(' ')<<right<<"#"<<endl;
	cout<<"#"<<setw(86)<<setfill('#')<<"#"<<endl<<endl<<endl;
}
char dashboard(){
	char choice;	
	
	header();
	cout<<"\t\t1. Create New Account"<<endl;
	cout<<"\t\t2. Withdraw Amount"<<endl;
	cout<<"\t\t3. Add Amount"<<endl;
	cout<<"\t\t4. Display Records"<<endl;
	cout<<"\t\t5. Exit"<<endl;	
	cout<<"\n\t\tEnter your choice:"; cin>>choice;
	cin.ignore();
	return choice;
}

int createAccount(char file[]){
	fstream f(file,ios::in | ios::app);
	header();
	BankAccount acc;
	int accNo;
	
	if(!f.is_open()){
		cerr<<"Error while opening file..";
		return 1;
	}
	
	if(!f.seekg(-sizeof(acc),ios::end)) accNo = 100;
	else{
		f.read((char*)&acc,sizeof(acc));
		accNo = 1 + acc.getAccNo();
	}
	f.clear();
	
	f.seekp(0,ios::end);
	acc.setData(accNo);
	if(f.write((char*)&acc,sizeof(acc)) == 0) cout<<"\n\tError while writing data..."<<endl;
	else cout<<"\n\tNew Account created successfully..."<<endl;
	f.close();
	getch();
}

void displayAccounts(char stream[]){
	ifstream file(stream);
	header();
	BankAccount acc;
	
	cout<<left<<setfill('-');
	cout<<setw(10)<<"+"<<setw(20)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
	cout<<setfill(' ');
	cout<<setw(10)<<"| AccNo."<<setw(20)<<"| AccHolder Name"<<setw(6)<<"| Age"<<setw(10)<<"| Gender"<<setw(15)<<"| Address"<<setw(10)<<"| AccType"<<setw(15)<<"| Balance"<<"|"<<endl;
	cout<<setfill('-');
	cout<<setw(10)<<"+"<<setw(20)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
	cout<<setfill(' ');
	
	file.seekg(0,ios::end);
	if(file.tellg()){
		file.seekg(0,ios::beg);
		while(file.read((char*)&acc,sizeof(acc))){
			acc.getData();	
		}
	}
	else{
		cerr<<"\t---------- No Record found ---------"<<endl;
	}
	
	cout<<setfill('-');
	cout<<setw(10)<<"+"<<setw(20)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
	file.close();
	getch();
}

void End(){
	header();
	cout<<"\t\t\t!!!!  Thankyou For your Time.  !!!!!"<<endl;
	getch();
}

int main(){
	char filestream[] = "accounts.txt";
	
	fstream file(filestream);
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
				cout<<"\n\t\t!!! Invalid choice !!!!"; getch();
		}
	}while(choice != '5');
	
	return 0;	
}
