#include<stdio.h>
#include<string.h>

struct employee{
	int id;
	char name[20];
	float salary;
};

int main(){
 	FILE *file;
 	struct employee emp;
 	char ch,sname[20];
 	int df = 0; // data found..
 	
 	file = fopen("employee.txt","a+b");
 	if(file == NULL){
 		printf("\n!!! Error !!!  file can't open...'");
 		return 1;
	 }
 	
 	printf("Enter the record of employee...\n");
 	do
 	{
 		printf("ID: "); scanf("%d",&emp.id);
 		printf("Name: "); scanf("%s",emp.name);
 		printf("Salary: "); scanf("%f",&emp.salary);
 		
 		if(!fwrite(&emp,sizeof(emp),1,file)){
 			printf("\n!!! Error while write the data !!!\n");
 			return 1;
		 }
 		
 		printf("\nDo you want to add more [y/n]:");
 		scanf("%s",&ch);
	}while(ch == 'Y' || ch == 'y');
	
	printf("\nEnter the name to search: ");
	scanf("%s",sname);
	
	rewind(file);
	while(fread(&emp,sizeof(emp),1,file)){
		if(strcmp(emp.name,sname) == 0){
			df = 1;
			printf("\nID: %d",emp.id); 
	 		printf("\nName: %s",emp.name); 
	 		printf("\nSalary: %.2f\n",emp.salary);
		}
	}
	if(df == 0){
		printf("\nData not found...");
	}
	
	fclose(file);
 	return 0;
 }
