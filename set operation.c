#include<stdio.h>

void display(int arr[],int size){
	int i;
	for(i=0;i<size;i++)
		printf("%d ",arr[i]);
	printf("\n");
}

void Union(int a[],int b[],int m,int n){
	int i,j,k;
	int common[50],c_len=0,count=0;
	int u[50];
	
	for(i=0;i<m;i++) 
		u[count++] = a[i];
		
	for(i=0;i<n;i++){
		for(j=0;j<count;j++){
			if(b[i] == u[j]) break;
		}
		if(j==count) u[count++] = b[i];
	}
	
	printf("\n A U B : ");
	display(u,count);
}

void Intersection(int a[],int b[],int m,int n){
	int i,j,count=0;
	int intr[50];
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				intr[count++]=a[i];
				break;
			}
		}
	}
	
	printf("\n A n B : ");
	display(intr,count);
}

void Difference(int a[], int b[],int m, int n){
	int result[50],count = 0;
	int isEqual = 0;
	int i,j;
	
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(a[i] != b[j]){
				isEqual = 0;
			}else{
				isEqual = 1;
				break;
			} 
		}
		if(!isEqual) result[count++] = a[i];
	}
	printf("\n A - B : ");
	display(result,count);
}

int main(){
	int a[50],b[50];
	int m,n,i,j;
	
	printf("Enter the size of A and B:"); scanf("%d%d",&m,&n);
	
	printf("\nEnter elements of A:\n");
	for(i=0;i<m;i++)
		scanf("%d",&a[i]);
		
	printf("\nEnter elements of B:\n");
	for(i=0;i<n;i++)
		scanf("%d",&b[i]);
		
	Intersection(a,b,m,n);
	Union(a,b,m,n);
	Difference(a,b,m,n);
	
	return 0;
}
