#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<unistd.h>

void RunChild()
{
    while(1)
    {
        printf("I am parent,pid: %d,ppid: %d\n",getpid(),getppid());
        //代码后面的geipid和getppid是获取父进程和子进程id
        sleep(1);
    }
}
int main()
{
    // const int num = 5;
    // //表示要创建子进程的个数
    // for(int i = 0;i<num;i++)
    // {
    //     pid_t id = fork();
    //     if(id == 0)
    //     //在这个代码中，程序可以通过 id的检查，判断当前是在父进程还是子进程中执行
    //     // 如果>0 那么这段代码会在父进程中执行，在本代码中相当于创建了五个子进程
    //     //如果-1，那么创建失败 
    //     {
    //         RunChild();
    //     }
    // }
    // return 0;




   printf("process is running, only me!, pid: %d\n", getpid());
   sleep(3);
   pid_t id = fork();
   if(id == -1) return 1;
   else if(id == 0)
   {
       // child
       while(1)
       {
           printf("id: %d, I am child process, pid: %d, ppid: %d\n", id, getpid(), getppid());
           sleep(1);
       }
   }
   else
   {
       // parent
       while(1)
       {
           printf("id: %d, I am parent process, pid: %d, ppid: %d\n", id, getpid(), getppid());
           sleep(2);
       }
   }
    return 0;
}

//上面代码展示了，通过 fork()创建了一个子进程，根据这个函数的返回值
//来区分父进程和子进程。
//返回-1，创建失败，程序返回1并推出
//返回0，表示当前在子进程中执行，进入子进程代码块
//大于0，返回大于0的值，(子进程的PID)，表示当前是在父进程中执行
//进入父进程代码块

//根据结论，父进程会2秒打印一次自己的pid和子进程的pid
//子进程1秒打印1次自己的pid和父进程的pid