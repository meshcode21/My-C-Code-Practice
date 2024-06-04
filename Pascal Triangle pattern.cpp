#include<stdio.h>
#include<conio.h>

int main(){
	int n;
	int i,j,k,l=0;
	
	printf("Enter N:");
	scanf("%d",&n);
	

	for(i=1;i<=n;i++){
		for(j=n;j>i;j--)
			printf("   ");
		
		for(k=1;k<=(i*2)-1;k++){
			if(k<=i)
				printf("%d  ",k);
			else if(k>i){
				l+=2;
				printf("%d  ",k-l);
			}
		}
		l=0;	
		printf("\n\n");
	}

	getch();
}
