#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 int main(){
 	char string[50],temp[50];
 	int i,len;
 	
 	printf("enter the string:");
 	gets(string);
 	len = strlen(string);
 	
 	for(i=0; i<len/2;i++){
 		if(string[i] != string[(len-1)-i]){
 			printf("\nThe string \"%s\" is not palendrum.",string);
 			exit(0);
		 }
	 }
	 printf("\nThe string \"%s\" is palendrum.",string);
	 return 0;
 }
