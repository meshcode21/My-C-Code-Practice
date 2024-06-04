#include<stdio.h>
main(){
	int a[10][10],b[10][10],c[10][10];
	int i,j,k;
	int ar,ac, br,bc;
	
	printf("Enter the size of 1st matrix ([A]r*c): ");
	scanf("%d%d",&ar,&ac);
	printf("Enter the size of 2st matrix ([B]r*c): ");
	scanf("%d%d",&br,&bc);
	
	if(ac == br){
		printf("\nEnter 1st matrix elements ([A]%dx%d):\n",ar,ac);
		for(i=0;i<ar;i++){
			for(j=0;j<ac;j++)
				scanf("%d",&a[i][j]);
		}
		printf("\nEnter 2nd matrix elements ([B]%dx%d):\n",br,bc);
		for(i=0;i<br;i++){
			for(j=0;j<bc;j++)
				scanf("%d",&b[i][j]);
		}
		
		
		// multiplying 2 matrixes...
		for(i=0;i<ar;i++){
			for(j=0;j<bc;j++){
				c[i][j] = 0;
				for(k=0;k<br;k++){
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		
		//displaying result.....
		printf("\nThe result is A(%dx%d) X B(%dx%d):\n\n",ar,ac,br,bc);
		for(i=0;i<ar;i++){
			for(j=0;j<bc;j++)
				printf("\t%d",c[i][j]);
			printf("\n");
		}
	}
	else{
		printf("\nRow of 1st matrix is must be equal to column of 2nd matrix.");
	}
	
}
