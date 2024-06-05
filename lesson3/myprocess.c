#include<stdio.h>

int AddToTarget(int start,int end)
{
    int i = start;
    int sum = 0;
    for(; i <= end;i++)
    {
        sum += i;
    }
    return sum;
}
//原 lesson11


int main()
{
    printf("run begin...\n");
    int result = 0;
    result = AddToTarget(1,100);
    printf("result: %d\n",result);
    printf("run end...\n");
}