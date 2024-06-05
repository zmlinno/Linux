#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>

void RunChild()
{
        while(1)
        {
                printf("I am parent,pid: %d,ppid: %d\n",getpid(),getppid());
                sleep(1);
        }
}


int main()
{
        return 0;
}