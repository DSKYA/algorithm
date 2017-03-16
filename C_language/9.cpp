// 最大的矩形
// Created by cxj on 17-3-16.
//

#include "stdio.h"
int main()
{
    long long max = -1;
    int n;
    long long anct[1005][1005];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%lld",&anct[i][i]);
       // printf("%lld ",anct[i][i]);
    }

    for(int i = 1; i <= n; i++)
        for(int j = i + 1; j <= n; j++)
        {
            int depth = anct[i][j - 1] / (j - i);
            if(anct[j][j] < depth)anct[i][j] = anct[j][j] * (j - i + 1);
            else anct[i][j] = anct[i][j - 1] + depth;
            if(max < anct[i][j])max = anct[i][j];
          //  printf("%d %d -%lld\n",i,j,anct[i][j]);
        }
    printf("%lld",max);
    return 0;
}