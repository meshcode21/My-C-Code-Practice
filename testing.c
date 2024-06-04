 #include<stdio.h>
 	
struct student{ 
	int id;
	char name[20];
};

void display(FILE *f){	
	int id; char name[20];
//	(void)fseek(f, 0L, SEEK_SET);
	rewind(f);
	printf("\nThe records of students.\n\nID\tName");
	while(fscanf(f,"id: %d , name: %s\n",&id,name) != EOF)
		printf("\n%d\t\%s",id,name);
}

void record(struct student std[],FILE *f){
	int i;
	for(i=0;i<5;i++)
		fprintf(f,"id: %d , name: %s\n",std[i].id,std[i].name);
}

void main(){
	struct student std[5];	int i;	
	int id; char name[20];
 	FILE *file;
	file = fopen("student.txt","a+"); // file opening...
	
	printf("Enter record of 5 students.\n");	
	for(i=0;i<5;i++){
		printf("\nEnter ID:"); scanf("%d",&std[i].id);
		printf("Enter name:"); scanf("%s",&std[i].name);
	}
	record(std,file);

	printf("\nThe data successfully recorded in file..\n");
	display(file); 
	
 	fclose(file); // file closing...
}
