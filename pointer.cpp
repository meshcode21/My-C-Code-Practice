#include<stdio.h>
void swap(int *x,int *y){
	int temp = *x;
	*x = *y;
	*y = temp;
	
}

int sum(int x[],int n){
	int s=0,i;
	for(i=0;i<n;i++)
		s += x[i];
		
	return s;
}
 
int main(){
	int a = 5, b=6;
	int ar[] = {1,2,3,4,5};
	
	printf("A = %d\nB = %d",a,b);
	printf("\nAfter swaping\n");
	swap(&a,&b);
	printf("A = %d\nB = %d",a,b);
	
	printf("\n Sum of Array is: %d",sum(ar,5));
	return 0;
}
