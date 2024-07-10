#include<stdio.h>

// To check if entered data is binary or not..
int isBinary(char arr[],int size){
	int i, t=1;
	for(i=0;i<size;i++)
		if(arr[i]!='0' && arr[i]!='1') return 0;
	return 1;
}

// To find the length of bits...
int length(char arr[]){
	int i,count=0;	
	for(i=0; arr[i]!='\0'; i++)
		count++;		
	return count;
}

// To match bits with another...
void bitMatch(char arr[], int n){
	int i,j;
	int var;
	int	arrlen = length(arr);
	
	for(i=0; i < (n-arrlen); i++){
		var = length(arr);
		for(j=var; j > 0; j--)
			arr[j] = arr[j-1];
		arr[0] = '0';
		arr[var+1] = '\0';
	}
}

// To Make both bits equal...
void makeEqualBits(char a[], char b[]){
	int al = length(a), bl = length(b);
	
	if(al > bl)		bitMatch(b,al);
	else if(bl > al)	bitMatch(a,bl);	
}

// Adding two binary numbers...
void addBinary(char aArr[], char bArr[],char result[],int size){
	int d = 0,c = 0,i,j;
	int a,b;
	
	for(i=size-1;i>=0;i--){
		a = (aArr[i]=='1')?1:0;
		b = (bArr[i]=='1')?1:0;
		
		// Addition algorithm implementation...
		d = (a + b + c)%2;
		c = (a + b + c)/2;		
		result[i] = d?'1':'0';
	}
	
	if(c){ // carry added if exist...
		for(j=size; j > 0; j--)
			result[j] = result[j-1];
		result[0] = c?'1':'0';
		size++;
	}
	result[size] = '\0';
}

int main(){
	char a[50],b[50],sum[50]; //array to read binary number
	int n;	//define size of binary bits..
	
	printf("Enter first binary number: "); scanf("%s",a);
	printf("Enter second binary number: "); scanf("%s",b);
	
	//Error handling....
	if(!isBinary(a,length(a)) || !isBinary(b,length(b))){
		printf("\n\t!!! Invalid input Error !!!\n"); 
		return 0;
	}
	
	makeEqualBits(a,b);
	addBinary(a,b,sum,length(a));
	
	printf("\nA: %s\nB: %s",a,b);
	printf("\n\nSum: %s",sum);
	
	return 0;
}
