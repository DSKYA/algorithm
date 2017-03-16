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
    //bool hasNode[600];
    scanf("%d",&n);
   // printf("\n%d\n",n);
    arry[0] = 1;
    //for (int i = 1; i <= (n - 1)/2; i++) {
        /*
        sum = 1;
        for(int j = n - 1; j >= n - i; j--)hasNode[j] = false;
        int j = 2;
        while(j <= i)
        {
            bool flg = false;
            if(sum % j == 0)
            {
                sum = sum / j;
                j++;
                flg = true;
            }
            for(int k = n - 1;!flg && k >= n - i; k--)
            {
                if(!hasNode[k] && ((sum * k) % j) == 0)
                {
                    sum = sum * k / j;
                    sum = sum % MOD;
                    hasNode[k] = true;
                    j++;
                    flg = true;
                    break;
                }
            }
            if(!flg)
            {
                int k = n - 1;
                while(k > n - i && hasNode[k])k--;
                sum = sum * k;
                hasNode[k] = true;
            }
        }
        for(int k = n - 1; k >= n - i; k--)
        {
            if(!hasNode[k])
            {
                sum = sum * k;
                sum = sum % MOD;
            }
        }
        arry[i] = sum;
         */
    //}
        for(int i = 1; i <= n; i++) {
            C_number[i][1] = i;
            C_number[i][i] = 1;
        }
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
                //printf("%d %d - %d\n",i,j,C_number[i][j]);
            }
        }
        //printf("%d %lld\n",i,arry[i]);
    sum = 0;
    for(int i = 2; i <= n - 2; i++)
    {
        //if(i <= (n - 1)/2)sum += arry[i] * (i - 1) * (n - 1 - i);
        //else sum += arry[n - 1 - i] * (i - 1) * (n - 1 -i);
        sum += C_number[n - 1][i] * (i - 1) * (n - 1 - i);
        sum = sum % MOD;
  //      printf("%lld ",sum);
    }
 //   printf("\n");
    printf("%lld",sum);
    return 0;
}

