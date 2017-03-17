//窗口
// Created by cxj on 17-3-17.
//

#include "stdio.h"
struct
{
    int x1,x2;
    int y1,y2;
    int seq;
}stack[30];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int top = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d %d %d",&stack[top].x1,&stack[top].y1,&stack[top].x2,&stack[top].y2);
        stack[top].seq = i;
        top++;
    }
    for (int j = 0; j < m; j++)
    {
        int x,y;
        scanf("%d %d"&x,&y);
        bool has_get = false;
        int i = top - 1;
        while(i >= 0)
        {
            if(stack[i].seq)
                if(stack[i].x1 < x && x < stack[i].x2 && stack[i].y1 < y && stack[i].y2 > y){has_get = true;break;}
            i--;
        }
        if(has_get)
        {
            printf("%d",stack[i].seq);
            stack[top].seq = stack[i].seq;
            stack[top].x1  = stack[i].x1;
            stack[top].x2  = stack[i].x2;
            stack[top].y1  = stack[i].y1;
            stack[top].y2  = stack[i].y2;
            top++;
            stack[i].seq = 0;
        }
        else
        {
            printf("IGNORED");
        }
        if(j < m -1)printf("\n");
    }
    return 0;
}