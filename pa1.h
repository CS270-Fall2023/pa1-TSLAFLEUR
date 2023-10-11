/**
 * @file pa1.h
 * @author Tyler LaFleur
 * @brief This file contains all necessary libraries and function prototypes for pa1
 * @version 0.1
 * @date 2023-10-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef PA1_H
#define PA1_H

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int getTokens(char *s, char ***args);
void printTokens(int numberOfTokens,char ***args);

#endif