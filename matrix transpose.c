#include<stdio.h>
main(){
	int a[10][10],tp[10][10];
	int i , j , row , col ;
	
	printf("Enter the size of 1st matrix ([A]r*c): ");
	scanf("%d%d",&row,&col);
	
	
	printf("\nEnter matrix elements ([A]%dx%d):\n",row,col);
	for(i=0;i<row;i++){
		for(j=0;j<col;j++)
			scanf("%d",&a[i][j]);
	}
	
	
	// transpoing matrix...
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			tp[j][i] = a[i][j];
		}
	}
	
	//displaying result.....
	printf("\nThe transpose of A(%dx%d):\n\n",row,col);
	for(i=0;i<col;i++){
		for(j=0;j<row;j++)
			printf("\t%d",tp[i][j]);
		printf("\n");
	}

}
