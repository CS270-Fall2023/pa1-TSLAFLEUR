/**
 * @file pa1.c
 * @author Tyler LaFleur
 * @brief This file contains all function definitions required for pa1
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pa1.h"


/**
 * @brief This function gets all tokens from s and puts them into args
 * 
 * @param s 
 * @param args 
 * @return int 
 */
int getTokens(char *s, char ***args){
	int count=0,
		inToken=1;
	//count the number of tokens in string
	for(int i=0;i<strlen(s);i++){
		if((s[i]==' '||s[i]=='\n')&&inToken==1){
			inToken=0;
			count++;
		}else if(s[i]!=' '&&inToken==0){
			inToken=1;
		}
	}
	//allocate space in array for pointers to strings equal to number of count
	(*args)=malloc((count+1)*sizeof(char*));
	inToken=1;
	int start=0,
		end=0,
		index=0;
	//find start&end of tokens, allocate memory location for tokens, then copy tokens to array of pointers to strings
	for(int i=0;i<strlen(s);i++){
		int length=0;;
		//if end of token
		if((s[i]==' '||s[i]=='\n')&&inToken==1){
			end=i;
			length=end-start;
			//allocate memory for string in array of pointers to string
			(*args)[index]=malloc((length+1)*sizeof(char));
			//copy token to string
			strncpy((*args)[index],s+start,length);
			inToken=0;
			index++;
		}//if start of new token
		else if(s[i]!=' '&&inToken==0){
			start=i;
			inToken=1;
		}
	}
	return count;
}

/**
 * @brief this function prints all tokens from args
 * 
 * @param numberOfTokens 
 * @param args 
 */
void printTokens(int numberOfTokens,char ***args){
	printf("Number of tokens: %d\n",numberOfTokens);fflush(stdout);
	for(int i=0;i<=numberOfTokens;i++){
		printf("token %d: %s\n",i+1,(*args)[i]);fflush(stdout);
	}
}