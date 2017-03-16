//无线网络
// Created by cxj on 17-3-16.
//

#include "stdio.h"
#include "math.h"
#define MAX 10000

long long cal(long long x1,long long y1,long long x2,long long y2)
{
   // printf("%lld %lld %lld %lld - %lld\n",x1,y1,x2,y2,(x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) );
    //return (long long)sqrt((double)((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)));
    return ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    int  n,m,k;
    long long r;
    long long loca_x[202],loca_y[202];
    int arriv[202] = {0};
    int number[202] = {0};
    int seq[MAX];
    int head,last;
    scanf("%d %d %d",&n, &m, &k);
    scanf("%lld",&r);
    for(int i = 1; i <= n + m; i++) {
        scanf("%lld %lld",&loca_x[i],&loca_y[i]);
    }
    head = 0;
    arriv[1] = 1;
    seq[head] = 1;
    last = 1;
    while(head < last)
    {
        if(head > MAX)
        {
            head -= MAX;
            last -= MAX;
        }
        int tmp = seq[head % MAX];
        if(tmp == 2)break;
        for(int i = 1; i <= m + n; i++)
        {
           // printf("%lld\n",cal(loca_x[tmp],loca_y[tmp],loca_x[i],loca_y[i]));
           // if(!arriv[i]&&cal(loca_x[tmp],loca_y[tmp],loca_x[i],loca_y[i]) <= r)
            if(!arriv[i]&&cal(loca_x[tmp],loca_y[tmp],loca_x[i],loca_y[i]) <= r * r)
            {
                if(i > n && number[tmp] < k)
                {
                    seq[last % MAX] = i;
                    last++;
                    arriv[i] = arriv[tmp] + 1;
                    number[i] = number[tmp] + 1;
                }
                else if(i <= n)
                {
                    seq[last % MAX] = i;
                    last++;
                    arriv[i] = arriv[tmp] + 1;
                }
            }
        }
       // printf("%d\n",tmp);
        head++;
    }
    printf("%d",arriv[2] - 2);
}