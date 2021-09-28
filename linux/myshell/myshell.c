#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#define SIZE 256
#define NUM 16
int main()
{
  char cmd[SIZE];
  const char cmd_line[]="[myshell@VM-0-11-centos myshell]$";
  while(1)
  {
    cmd[0]='\0';
    printf("%s ",cmd_line);
    char *argv[NUM];
    fgets(cmd,SIZE,stdin);
    cmd[strlen(cmd)-1]='\0';
    argv[0]=strtok(cmd," ");
    int i=1;
    while(1)
    {
      argv[i]=strtok(NULL," ");
      if( argv[i] ==NULL)
      {
        break;
      }
      ++i;
    }

    pid_t id=fork();
    if(id<0)
    {
      perror("fork error\n");
      continue;
    }
    if(id==0)
    {
      execvp(argv[0],argv);
      exit(1);
    }
    int status=0;
    pid_t ret=waitpid(id,&status,0);  //父进程以阻塞的方式等待子进程
    if(ret>0)
    {
      if((status&0x7f)==0) //WIFEXITED
      {
        printf("child exit code:%d\n",(status>>8)&0xff); //WEXITED 查看子进程正常退出的退出码
      }
      else
      {
        printf("sign code:%d\n",status&0x7F);
      }
    }
  }
  return 0;
}
