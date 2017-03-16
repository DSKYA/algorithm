//
// Created by cxj on 17-3-16.
// 有趣的数
//
#include "stdio.h"
int n;
long long sum = 0;
int stack[1005];
int number[4] = {0};
int a1 = 1001;
int a3 = 1001;
int stackagain(int top)
{
    if(top > n)
    {
        if(number[0] && number[1] && number[2] && number[3])
        {
            sum += 1;
            sum = sum % 1000000007;
            //printf("\n");
            //for(int i = 1; i <= n; i++)
            // printf("%d ",stack[i]);
            //printf("%d %d %d %d OK\n",number[0],number[1],number[2],number[3]);
        }
        return 0;
    }
    for(int i = 0; i < 4; i++)
    {
        if(i == 1)
        {
            int tmp;
            tmp = a1;
            a1 = top;
            stack[top] = 1;
            number[1]++;
            //printf(" 1");
            stackagain(top + 1);
            number[1]--;
            a1 = tmp;
        }
        else if(i == 0)
        {
            if(top < a1)
            {
                stack[top] = 0;
                number[0]++;
                //printf(" 0");
                stackagain(top + 1);
                number[0]--;
            }
        }
        else if(i == 3)
        {
            int tmp;
            tmp = a3;
            a3 = top;
            stack[top] = 3;
            number[3]++;
            //printf(" 3");
            stackagain(top + 1);
            number[3]--;
            a3 = tmp;
        }
        else
        {
            if(top < a3)
            {
                stack[top] = 2;
                number[2]++;
                //printf(" 2");
                stackagain(top + 1);
                number[2]--;
            }
        }
    }
    return 0;
}
int main()
{
    int top = 1;
    scanf("%d",&n);
    stack[top] = 2;
    number[2]++;
    top++;
    stackagain(top);
    //printf("answer!\n");
    printf("%lld",sum);
    return 0;
}
