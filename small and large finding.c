#include<stdio.h>

void input(int x[],int n){
	int i;
	// initialization of array elements.....
	printf("\nEnter %d numbers: \n",n);
	for(i=0;i<n;i++)
		scanf("%d",&x[i]);
}

int largest(int x[],int n){
	int i , largest = x[0];
	// Largest value finding operation...
	for(i=0;i<n;i++){
		if(x[i] > largest)
			largest = x[i];
	}
	return largest;
}
int main(){
	int a[100],n,large;
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	input(a,n);
	large = largest(a,n);
		
	printf("\nThe largest number is: %d",large);
}
