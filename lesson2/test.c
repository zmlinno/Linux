#include<stdio.h>
#include<unistd.h>
//这个代码是包含UNIX标准函数库，用于使用 sleep函数

int main()
{
    int cnt = 10;
    while(cnt >= 0)
    {
        printf("倒计时: %2d\r",cnt);
        //打印当前的倒计时数字，并使用\r回到行首以覆盖前一次的输出
        fflush(stdout);
        //刷新输出缓冲区，确保即时输出
        cnt--;
        sleep(1);
    }
    printf("\n");

    return 0;
}