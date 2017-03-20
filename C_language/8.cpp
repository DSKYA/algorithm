//
// Created by cxj on 17-3-16.
//

#include "stdio.h"
#define MOD 1000000007

int main()
{
    long long arry[600];
    long long sum = 0;
    long long C_number[1005][1005] = {0};
    int n;
    scanf("%d",&n);
    arry[0] = 1;
/*
c(i,1)赋值1 和 c(i,i)赋值1
*/
        for(int i = 1; i <= n; i++) {
            C_number[i][1] = i;
            C_number[i][i] = 1;
        }
/*
计算整个组合表
*/
        for(int i = 2; i < n; i++)
        {
            for(int j = 2; j < i; j++)
            {
                if(C_number[i][i - j])C_number[i][j] = C_number[i][i - j];
                else
                {
                    for(int k = j - 1; k < i; k++)
                    {
                        C_number[i][j] += C_number[k][j - 1];
                        C_number[i][j] = C_number[i][j] % MOD;
                    }
                }
            }
        }
/*
组后的求和公式
*/
    sum = 0;
    for(int i = 2; i <= n - 2; i++)
    {
        sum += C_number[n - 1][i] * (i - 1) * (n - 1 - i);
        sum = sum % MOD;
    }
    printf("%lld",sum);
    return 0;
}

