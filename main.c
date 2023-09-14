/**
 * @file main.c
 * @author Tyler LaFleur
 * @brief This file asks the user to enter a string. It will convert the string into tokens
 *        and inform the user to the number of tokens and what each token is.
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pa1.h"
#include <stdio.h>

int main(){
    char tokenString[256];
    char **tokenArray;
    int numOfToken=0;

    printf("Please, enter the string: ");
    fgets(tokenString,256,stdin);
    numOfToken=getTokens(tokenString, &tokenArray);//convert string into tokens

    printf("Number of tokens: %i\n",numOfToken);
    for(int i=0;i<numOfToken;i++){//print each token
        printf("token %i: %s\n",i+1,tokenArray[i]);
    }

    return 0;
}