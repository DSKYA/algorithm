//出现次数最多的数
// Created by cxj on 17-3-16.
//

#include "stdio.h"

int main()
{
    int n;
    int bal[10001] = {0};
    int max = 0;
    int seq = 1;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        scanf("%d",&tmp);
        bal[tmp]++;
    }
    for(int i = 1; i <= 10000; i++)
    {
        if(bal[i] > max){seq = i;max = bal[i];}
    }
    printf("%d",seq);
    return 0;
}