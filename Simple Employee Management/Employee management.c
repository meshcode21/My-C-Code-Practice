#include<stdio.h>
#include<stdlib.h>

struct employee{
	int id;
	char name[20];
	float salary;
};

int choose(){
	int choice;
	printf("\n1.Enter new Record\n2.Display Records\n3.Search Records\n4.Exit\n");
	printf("\nEnter your choice: ");
	scanf("%d",&choice);
	if(choice>=1 && choice<=4) return choice;
	else return 0;
}

void new_record(FILE *f, struct employee e){
	char ch;
	system("cls");
	do{
		printf("\nEnter new employee records..\n\n");
		printf("Enter Name: "); scanf("%s",e.name);
		printf("Enter Id: "); scanf("%d",&e.id);
		printf("Ener Salary: "); scanf("%f",&e.salary);
		fwrite(&e,sizeof(e),1,f);

		printf("\nContinue the record [y/n]:"); scanf("%c",&ch);
	}while(ch == 'y');
}

void display_record(FILE *f, struct employee e){
	system("cls");
	printf("\nList of Employees...\n\n");
	printf("ID\tName\tSalary\n");
	printf("-------------------------\n");
	rewind(f);
	while(fread(&e,sizeof(e),1,f)){
		printf("%d\t%s\t%.2f\n",e.id,e.name,e.salary);
	}
	printf("-------------------------\n");
	getch();
	
}

void search(FILE *f, struct employee e){
	char sname[20];
	system("cls");
	printf("Enter Name to search: "); scanf("%s",sname);
	
	printf("\nList of Employees...\n\n");
	printf("ID\tName\tSalary\n");
	printf("-------------------------\n");
	rewind(f);
	while(fread(&e,sizeof(e),1,f)){
		if(strcmp(e.name,sname) == 0)
			printf("%d\t%s\t%.2f\n",e.id,e.name,e.salary);
	}
	printf("-------------------------\n");
	printf("\nThe record(s) of employee you trying to search..");
	getch();
}
void main(){
	FILE *file;
	file = fopen("employee.txt","a+b");
	
	struct employee emp;
	if(file != NULL){
		while(1){
			system("cls");
			switch(choose()){
				case 1: new_record(file,emp); break;
				case 2: display_record(file,emp); break;
				case 3: search(file,emp); break;
				case 4: exit(0); break;
				default: printf("!!! Wrong Choice !!!"); getch();
			}
		}
	}else{
		printf("Error Whie opening the file...");
	}
	fclose(file);
}
