#include<stdio.h>

void main(){
	FILE *file;
	int arr[5];
	int i=0;
//	void *n;
	
	file = fopen("text.bat","rb");
	
	fread(arr,sizeof(arr),1,file);
	
	for(i=0;i<5;i++)
		printf("%d ",arr[i]);
		
	fclose(file);
	
//	printf("successful...\n");
}
