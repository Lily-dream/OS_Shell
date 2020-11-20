#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<string.h>
#include "parse.h"
#include "externs.h"
#include "init.h"
#include "def.h"


/*
 * shell主循环
 */
void shell_loop(void){
    while(1){
        printf("[myshell]$ ");
        fflush(stdout);
        /* 初始化环境 */
        init();
        if(read_command() == -1)
            break;
        parse_command();
        char *command;
        execute_command(); 
    }
    printf("\nexit\n");
}

/*
 * 读取命令
 * 成功返回0，失败或者读取到文件结束符(EOF)返回-1
 */
int read_command(void){
    if(fgets(cmdline,MAXLINE,stdin) == NULL){
        return -1;
    }
    return 0;
}

/*
 * 解析命令
 * 成功返回解析到的命令个数，失败返回-1
 */
int parse_command(void){
    char *cp = cmdline;
    char *avp = avline;

    int i = 0;
    while(*cp != '\0'){
        /** 去除左空格 **/
        while(*cp == ' ' || *cp == '\t')
            cp++;
        /* 如果到了行尾，跳出循环 */
        if(*cp == '\0' || *cp == '\n')
            break;
        cmd.args[i] = avp;
        
        while (*cp != '\0'
            && *cp != ' '
            && *cp != '\t'
            && *cp != '\n')
            *avp++ = *cp++;
        //printf("[%s]\n",cmd.args[i]);
        *avp++ = '\0';
        i++;
    }

    return 0;
}

/*
 * 执行命令
 * 成功返回0，失败返回-1
 */

/* 内建命令 cd 的实现 */
void cd(char *arg)
{
    if(arg == NULL)
    {
        printf("insufficient arguments\n");
    }
    else
    {
        int cond;
        cond = chdir(arg);
        if(cond == -1)
        {
            printf("wrong path\n");
        }
		
    }
}


int execute_command(void){
    pid_t pid = fork();
    if(pid == -1){
        //进程创建失败
        ERR_EXIT("fork");
    }
    if(pid == 0) {
        //子进程去执行替换函数
        execvp(cmd.args[0],cmd.args);
    } 
    //父进程等待子进程的退出,这样并不会改变父进程本身的行为，所以进程就不会退出了
    wait(NULL);
    return 0;
}

