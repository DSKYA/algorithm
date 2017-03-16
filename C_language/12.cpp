//
// Created by cxj on 17-3-16.
//
#include "stdio.h"


int main()
{
    int n;
    int timcp1 = 0;
    int timcp2 = 0;
    int timgp = 0;
    bool isrun[42] = {false};
    int time[42][6];
    int custom[42][6];
    scanf("%d",&n);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 4; j++)
        {
            scanf("%d",&time[i][j]);
            custom[i][j] = time[i][j] * j;
            if(j >= 3)custom[i][j] -= time[i][j];
            //printf("***%d %d\n",time[i][j],custom[i][j]);
        }
    }
    int hasrun = 0;

    while(hasrun < n)
    {
        int seq_x;
        int seq_y;
        int min = 20;
        int costmin = 60;
        for(int i = 1; i <= n; i++)
        {
            if(!isrun[i])
            {
                for(int j = 1; j <= 4; j++)
                {
                    if(time[i][j] < min) {
                        min = time[i][j];
                        costmin = custom[i][j];
                        seq_x = i;
                        seq_y = j;
                    }
                    else if(time[i][j] == min)
                    {
                        if(custom[i][j] < costmin)
                        {
                            min = time[i][j];
                            costmin = custom[i][j];
                            seq_x = i;
                            seq_y = j;
                        }
                    }
                }
            }
        }
        //printf("<>%d %d\n",seq_x,seq_y);
        if(seq_y == 1)
            if(timcp1 <= timcp2)timcp1 += time[seq_x][seq_y];
            else timcp2 += time[seq_x][seq_y];
        else if(seq_y == 2)
            {
                int tmp;
                if(timcp1 > timcp2)tmp = timcp1;
                else tmp = timcp2;
                timcp1 = tmp + time[seq_x][seq_y];
                timcp2 = tmp + time[seq_x][seq_y];
            }
        else if(seq_y == 3)
        {
                int tmp = timgp;
                if(timcp1 < timcp2)
                {
                    if(timgp < timcp1)tmp = timcp1;
                    timcp1 = tmp + time[seq_x][seq_y];
                    timgp = tmp + time[seq_x][seq_y];
                }
                else
                {
                    if(timgp < timcp2)tmp = timcp2;
                    timcp2 = tmp + time[seq_x][seq_y];
                    timgp = tmp + time[seq_x][seq_y];
                }
        }
        else
        {
            int tmp = timgp;
            if(tmp < timcp1)tmp = timcp1;
            if(tmp < timcp2)tmp = timcp2;
            timgp = tmp + time[seq_x][seq_y];
            timcp1 = tmp + time[seq_x][seq_y];
            timcp2 = tmp + time[seq_x][seq_y];
        }
        hasrun++;
        isrun[seq_x] = true;
       // printf("$$%d %d %d\n",timcp1,timcp2,timgp);
    }
    int tmp = timgp;
    if(tmp < timcp1)tmp = timcp1;
    if(tmp < timcp2)tmp = timcp2;
    printf("%d",tmp);
    return 0;
}
