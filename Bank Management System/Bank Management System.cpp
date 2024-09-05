#include<iostream>
#include<conio.h>
#include<fstream>
#include<iomanip>
#include <cstring>
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
	int getAccNo(){
		return accountNumber;
	}
	bool compareName(char n[]){
		if(strcmp(name,n) == 0) return true;
		else return false;
	}
	void setBalance(double b){
		balance = b;
	}
	double getBalance(){
		return balance;
	}
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
	again:
		cout<<"\n\tEnter Opening Balance: Rs."; cin>>balance;
		if(balance<0){
			cerr<<"\n\t\t!!!! Negative Balance Error !!!!"<<endl;
			goto again;
		}
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
		cout<<" | "<<setw(8)<<accountNumber<<"| "<<setw(23)<<name<<"| "<<setw(4)<<age<<"| "<<setw(8)<<gen<<"| "<<setw(13)<<address<<"| "<<setw(8)<<accType<<"| "<<setw(13)<<balance<<"|"<<endl;
	}
};

void header(int section){
	system("cls");
	cout<<"   #"<<setw(86)<<setfill('#')<<"#"<<endl;
	cout<<"   #"<<setw(86)<<setfill(' ')<<right<<"#"<<endl;
	cout<<"   #"<<setw(85)<<left<<"                       Welcome to Bank Management System"<<"#"<<endl;
	cout<<"   #"<<setw(86)<<setfill(' ')<<right<<"#"<<endl;
	cout<<"   #"<<setw(86)<<setfill('#')<<"#"<<endl<<endl;
	
	switch(section){
		case 0: cout<<"\t\tDashboard...\n"<<endl; break;
		case 1: cout<<"\t\tNew Account Create Section...\n"<<endl; break;
		case 2: cout<<"\t\tAccount Delete Section...\n"<<endl; break;
		case 3: cout<<"\t\tAmount Widthdraw Section...\n"<<endl; break;
		case 4: cout<<"\t\tAmount Add Section...\n"<<endl; break;
		case 5: cout<<"\t\tRecords Section...\n"<<endl; break;
		case 6: cout<<"\t\tSearch Account Section...\n"<<endl; break;
	}
}
char dashboard(){
	char choice;	
	
	header(0);
	cout<<"\t\t1. Create New Account\n"<<endl;
	cout<<"\t\t2. Delete Account\n"<<endl;
	cout<<"\t\t3. Withdraw Amount\n"<<endl;
	cout<<"\t\t4. Add Amount\n"<<endl;
	cout<<"\t\t5. Display Records\n"<<endl;
	cout<<"\t\t6. Search Account Record\n"<<endl;	
	cout<<"\t\t7. Exit\n"<<endl;	
	cout<<"\n\t\tEnter your choice:"; cin>>choice;
	cin.ignore();
	return choice;
}

void displayRecordHead(){
	cout<<left<<setfill('-');
	cout<<" "<<setw(10)<<"+"<<setw(25)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
	cout<<setfill(' ');
	cout<<" "<<setw(10)<<"| AccNo."<<setw(25)<<"| AccHolder Name"<<setw(6)<<"| Age"<<setw(10)<<"| Gender"<<setw(15)<<"| Address"<<setw(10)<<"| AccType"<<setw(15)<<"| Balance"<<"|"<<endl;
	cout<<setfill('-');
	cout<<" "<<setw(10)<<"+"<<setw(25)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
	cout<<setfill(' ');
}
void displayRecordEnd(){
	cout<<setfill('-');
	cout<<" "<<setw(10)<<"+"<<setw(25)<<"+"<<setw(6)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<setw(10)<<"+"<<setw(15)<<"+"<<"+"<<endl;
}

int createAccount(char file[]){
	fstream f(file,ios::in | ios::app);
	header(1);
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
	if(f.write((char*)&acc,sizeof(acc))) cout<<"\n\tNew Account created successfully..."<<endl;
	else cout<<"\n\tError while writing data..."<<endl;
	f.close();
	getch();
}

int deleteAccount(char filename[]){
	ifstream file(filename);
	ofstream tempfile("temp.txt",ios::app);
	BankAccount acc;
	int accNo;
	char ch;
	bool notfound = true;
	
	if(!file.is_open() && !tempfile.is_open()){
		cerr<<"Error while opening file..";
		return 1;
	}

	header(2);
	
	cout<<"\t\tEnter Acc. Number: "; cin>>accNo;

	file.seekg(0,ios::beg);
	while(file.read((char*)&acc,sizeof(acc))){
		if(acc.getAccNo() == accNo){
			notfound = false;
			displayRecordHead();
			acc.getData();
			displayRecordEnd();
		again:
			cout<<"\n\t\tDo you want to Delete this Account [y/n]: "; cin>>ch; cin.ignore();
			if(ch!='y' && ch!='n'){
				cerr<<"\n\t\t!!!! Invalid Choice  !!!!"<<endl;
				goto again;
			}
			if(ch == 'y'){
				cout<<"\n\t\tAccount Deleted successfully...."<<endl;
				continue;
			}		
		}		
		if(!tempfile.write((char*)&acc,sizeof(acc))) cerr<<"\t\tError while writing in temp file.."<<endl;
	}
	if(notfound) cerr<<"\n\t\tAccount not found..."<<endl;	
	file.close();
	tempfile.close();
	
	remove(filename);
	rename("temp.txt",filename);
	getch();
}

int Amount(char stream[],char mode){
	ifstream file(stream);
	ofstream tempfile("temp.txt",ios::app);
	BankAccount acc;
	int accNo;
	double balance;
	bool notfound = true;
	
	if(!file.is_open() && !tempfile.is_open()){
		cerr<<"Error while opening file..";
		return 1;
	}

	if(mode == 'w') header(3);
	else header(4);
	
	cout<<"\t\tEnter Acc. Number: "; cin>>accNo;

	file.seekg(0,ios::beg);
	while(file.read((char*)&acc,sizeof(acc))){
		if(acc.getAccNo() == accNo){
			notfound = false;
			displayRecordHead();
			acc.getData();
			displayRecordEnd();
		again:
			if(mode == 'w'){
				cout<<"\n\t\tEnter Amount to widthdraw: "; 	cin>>balance;	
				
				if(balance<=acc.getBalance()){
					acc.setBalance(acc.getBalance()-balance);
					cout<<"\n\t\tBalance Widthdraw Successful..."<<endl;
					cout<<"\t\tNew Balance is: "<<acc.getBalance()<<endl;
				}else{
					cerr<<"\n\t\t!!!! Insufficient balance  !!!!"<<endl;
					goto again;
				}
			} 
			else if(mode == 'a'){
				cout<<"\n\t\tEnter Amount to Add: ";  cin>>balance;
			
				if(balance >= 0){
					acc.setBalance(acc.getBalance()+balance);
					cout<<"\n\t\tBalance Added Successful..."<<endl;
					cout<<"\t\tNew Balance is: "<<acc.getBalance()<<endl;
				}else{
					cerr<<"\n\t\t!!!! Negative Balance Error !!!!"<<endl;
					goto again;
				}
			}		
		}		
		if(!tempfile.write((char*)&acc,sizeof(acc))) cerr<<"\t\tError while writing in temp file.."<<endl;
	}
	if(notfound) cerr<<"\n\t\tAccount not found..."<<endl;	
	file.close();
	tempfile.close();
	
	remove(stream);
	rename("temp.txt",stream);
	getch();
}

void displayAccounts(char stream[]){
	ifstream file(stream);
	BankAccount acc;
	
	header(5);
	displayRecordHead();
	
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
	
	displayRecordEnd();
	
	file.close();
	getch();
}

void searchAccount(char stream[]){
	ifstream file(stream);
	BankAccount acc;
	char ch, name[50];
	int accNo;
	bool notfound = true;
	
	
	header(6);
again:
	cout<<"\t\t1. AccNo.\n\t\t2. Name\n\n\t\tchoose: "; cin>>ch; cin.ignore();
	if(ch!='1' && ch!='2'){
		cout<<"\n\t\t!!! Invalid Choice !!!\n"<<endl;
		goto again;
	}
	
	if(ch=='1'){
		cout<<"\n\t\tEnter Account Number: "; cin>>accNo;
	}else{
		cout<<"\n\t\tEnter Name to Search: "; cin.getline(name,50);
	}
	
	displayRecordHead();
	
	file.seekg(0,ios::end);
	if(file.tellg()){
		file.seekg(0,ios::beg);
		if(ch=='1'){
			while(file.read((char*)&acc,sizeof(acc))){
				if(accNo == acc.getAccNo()){
					notfound = false;
					acc.getData();	break;
				}
			}
		}else{
			while(file.read((char*)&acc,sizeof(acc))){
				if(acc.compareName(name)){
					notfound = false;
					acc.getData();	
				}
			}
		}
	}
	
	if(notfound){
		cerr<<"\t---------- No Record found ---------"<<endl;
	}
	
	displayRecordEnd();
	
	file.close();
	getch();
}

void End(){
	header(7);
	cout<<"\t\t\t!!!!  Thankyou For your Time.  !!!!!"<<endl;
	getch();
}

int main(){
	char filename[] = "accounts.txt";
	
	ifstream file(filename);
	if(!file.is_open()){
		cout<<"something is wrong in file opening...!!";
		exit(1);
	}
	file.close();
	
	char choice;
	do{
		choice = dashboard();
		switch(choice){
			case '1':	createAccount(filename);	break;
			case '2':	deleteAccount(filename);	break;
			case '3':	Amount(filename,'w');	break;
			case '4': 	Amount(filename,'a');	break;
			case '5': 	displayAccounts(filename);	break;
			case '6': 	searchAccount(filename);	break;
			case '7': 	End();	break;
			default:
				cout<<"\n\t\t!!! Invalid choice !!!!"; getch();
		}
	}while(choice != '7');
	
	return 0;	
}
