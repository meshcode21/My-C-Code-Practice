#include<stdio.h>

int main(){
	FILE *file;
	int nums[10],i;
	
	file = fopen("number.txt","rb");
	if(file == NULL){
		printf("Error occured during file opening...!!!");
		return 1;
	}
//	printf("\nRead the array:\n");
//	for(i=0;i<10;i++)
//		scanf("%d",&nums[i]);
		
	if(!fread(&nums,sizeof(nums),1,file))
		printf("\nError to fetch the data !!!");
	else{
		printf("\nData successfully fetched..\n");
		printf("\nThe Array is:\n");
		for(i=0;i<10;i++)
			printf("%d ",nums[i]);
	}
	
	fclose(file); 
}
