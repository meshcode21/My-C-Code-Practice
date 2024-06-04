#include<stdio.h>
int main(){
	int a[100],n;
	int i , j , temp;
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	// initialization of array elements.....
	printf("\nEnter %d numbers: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		

	
	// Ascending ordering of inputs.....
	for(i=0;i<n-1;i++){
		for(j=i+1;j<n;j++){
			if(a[i] > a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}		
	}
	
	printf("\nThe numbers in ascending order are:\n");
	for(i=0;i<n;i++)
		printf(" %d",a[i]);
		
	return 0;
}
