#include <stdio.h>
#include <limits.h>

int main() {
    int n , i , min , max , sum = 0 ;
    float avg;
    
    printf("Enter the number of elements:");
    scanf("%d",&n);
    
    int num[n];
    
    printf("\nEnter the elememts:\n");
    for(i=0;i<n;i++)
    	scanf("%d",&num[i]);
    	
    min = num[0];
    max = num[0];
    
    for(i=0;i<n;i++){
    	if(num[i]<min)
    		min = num[i];
    	
		if(num[i]>max)
			max = num[i];
			
		sum += num[i];
	}
	
	avg = sum/n;
	
	printf("\n The Maximum number is: %d",max);
	printf("\n The Minimum number is: %d",min);
	printf("\n\n The Sum is: %d",sum);
	printf("\n The Average is: %.2f",avg);
	
    return 0;
}
