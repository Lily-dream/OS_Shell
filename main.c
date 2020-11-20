#include "parse.h"
#include "init.h"
#include "def.h"
char cmdline[MAXLINE+1];/*读取用户输入的命令行*/
char avline[MAXLINE+1];/*将用户输入的命令行以\0分隔，以便最终存放在cmd当中*/
COMMAND cmd;
int main(void){
	setup();
	/*进入shell循环*/
	shell_loop();
	return 0;

}
