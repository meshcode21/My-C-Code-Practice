#include<stdio.h>
#include<conio.h>

void read(){
	FILE *ptr;
	char string[100];
	ptr = fopen("text.txt","r");
	
	while(fgets(string,100,ptr))
	printf("%s",string);
	
	fclose(ptr);
}

void write(){
	FILE *ptr;
	char string[100];
	ptr = fopen("text.txt","w");
	
	fflush(stdin);
	fgets(string,100,stdin);
	fputs(string,ptr);
	printf("\n!!!! done !!!!");
	
	fclose(ptr);
}

void overwrite(){
	FILE *ptr;
	char string[100];
	ptr = fopen("text.txt","a+");
	
	while(fgets(string,100,ptr))
	printf("%s",string);
	
	fflush(stdin);
	fgets(string,100,stdin);
	fputs(string,ptr);
	printf("\n!!!! done !!!!");
	
	fclose(ptr);
}

int main(){
	int choice;
	
	while(1){
		system("cls");
		printf("\n.....Wellcome to text Editor....\n");
		printf("\n1.Read text\n2.Write text\n3.Overwride text\n4.exit\n");
		printf("\nEnter Your choice: "); 
		scanf("%d",&choice);
		printf("\n");
		
		switch(choice){
			case 1:  
				read();
			break;
			case 2: 
				write();
			break;
			case 3:
				overwrite();
			break;
			case 4:
				return 0;
			break;
			default: 
				printf("\n!!! wring choice.");
		}
		getch();
	}
}
