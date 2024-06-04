#include<stdio.h>

int main(){
	int p,q,i,j;
	int mat[10][10];
	int large[10];
	
	printf("Enter the size of matrix (PxQ): ");
	scanf("%d%d",&p,&q);
	
	printf("\nEnter the elements of matrix [%dX%d]\n",p,q);
	for(i=0;i<p;i++){
		for(j=0;j<q;j++){
			scanf("%d",&mat[i][j]);
		}
		//to find largest in row of matrix..
		large[i] = mat[i][0];
		for(j=1;j<q;j++){
			if(mat[i][j] > large[i]) 
				large[i] = mat[i][j];
		}
	}
	
	printf("\nThe largest values are\n");
	for(i=0;i<p;i++){
		printf("Row %d : %d\n",i+1,large[i]);
	}
	return 0;
}
