#ifndef _DEF_H_
#define _DEF_H_
#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 1024
#define MAXARG 20
#define PIPELINE 5
#define MAXNAME 100
#define MAX_COMM 100
#define ERR_EXIT(m)\
do\
{\
  perror(m);\
  exit(EXIT_FAILURE);\
}\
while(0)
typedef struct command{
char *args[MAXARG+1];
} COMMAND;


#endif /*DEF_H_*/
