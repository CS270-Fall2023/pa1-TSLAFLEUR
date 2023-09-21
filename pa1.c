/**
 * @file pa1.c
 * @author Tyler LaFleur
 * @brief This file contains function defintions needed for pa1 to get tokens from a string
 * @version 0.1
 * @date 2023-09-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "pa1.h"

/**
 * @brief This function accepts a string and a pointer to an array of strings.
 *        The string will be parsed for tokens which will be sorted into the array of strings
 *        The function returns the number of tokens, or -1 if an error occurs.
 * 
 * @param s string from user input that we will get tokens from
 * @param args array of strings to put tokens into
 * @return int return the number of tokens from string
 */
int getTokens(char *s, char **args[]){
    int stringStart=0,stringEnd=0,startOfNewToken=1,numberOfTokens=0;
    *args=malloc(((strlen(s)+1)/2)*sizeof(char));//reserve maximum possible number of strings in array
    for(int i=0;i<strlen(s);i++){
        //if current char is not space or null character and we expect a new token
        if(s[i]!=' '&&s[i]!='\0'&&startOfNewToken==1){
            startOfNewToken=0;
            stringStart=i;
            numberOfTokens++;
        }
        //if current char is a space or null character and we just finished a token
        else if((s[i]==' '&&startOfNewToken==0)||s[i]=='\n'){
            startOfNewToken=1;
            stringEnd=i;
            (*args)[numberOfTokens-1]=malloc((stringEnd-stringStart+1)*sizeof(char));//allocate memory in array for current token
            strncpy((*args)[numberOfTokens-1],s+stringStart,stringEnd-stringStart);//copy current token into array
        }
    }
    (*args)[numberOfTokens]=NULL;
    if(numberOfTokens>0){
        return numberOfTokens;
    }else{return -1;};
}