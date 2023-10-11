/**
 * @file main.c
 * @author Tyler LaFleur
 * @brief 	This file is used to retrieve tokens from a string inputted by the user.
 * 			The program will print out the number of tokens along with what the tokens are.
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pa1.h"

int main(){
	char 	**arrayOfTokens, 
			str[256];
	int numberOfTokens;
	printf("Please, enter the string: ");
	fgets(str,sizeof(char)*256,stdin);
	numberOfTokens = getTokens(str, &arrayOfTokens);
	printTokens(numberOfTokens, &arrayOfTokens);
	return 0;
}