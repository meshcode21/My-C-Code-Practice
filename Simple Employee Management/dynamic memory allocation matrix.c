#include<stdio.h>
#include<stdlib.h>

void main(){
	int r,c,i,j;
	int *mat;
	
	printf("Enter the size of matrix (r*c): ");
	scanf("%d%d",&r,&c);
	
	mat = (int*)calloc(r,c*sizeof(int));	
	
	printf("\nEnter the elements of matrix (%d*%d)\n",r,c);
	for(i=0;i<r;i++){	
		for(j=0;j<c;j++)
			scanf("%d",(mat+i)+j);
	}
	
	printf("\nThe elements of matrix (%d*%d) is\n",r,c);
	for(i=0;i<r;i++){	
		for(j=0;j<c;j++)
			printf("%d ",*(mat+i)+j);
		printf("\n");
	}
	
	free(mat);
}
