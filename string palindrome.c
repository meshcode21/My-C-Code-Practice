#include<stdio.h>

int length(char str[]){
	int len=0,i;
	for(i=0;str[i]!='\0';i++){
		len++;
	}
	return len;
}

int palindrome(char str[],int len){
	int i;
	for(i=0;i<len;i++){
		if(str[i] != str[(len-1)-i]) return 0;
	}
	return 1;
}
int main(){
	char str[50];
	int len;
	
	printf("enter the string: "); scanf("%s",str);
	len = length(str);
	
	if(palindrome(str,len)) printf("\nThe string \"%s\" is palendrome.",str);
	else printf("\nThe string \"%s\" is not palendrome.",str);
	
	return 0;
}
