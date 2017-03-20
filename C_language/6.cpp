//CCF-	I’m stuck! - 201312-5
// Created by cxj on 17-3-15.
//

#include "stdio.h"
#define MAX 40000
int n,m;
char road[50][50];

bool is_inside(int x,int y)
{
    if(x < 0)return false;
    if(y < 0)return false;
    if(x >= n)return false;
    if(y >= m)return false;
    if(road[x][y] == '#')return false;
    return true;
}

bool is_outside(int x,int y,int i)
{
    if(x < 0)return false;
    if(y < 0)return false;
    if(x >= n)return false;
    if(y >= m)return false;
    if(road[x][y] == '#')return false;
    switch (i)
    {
        case 1:
            if(road[x][y] == '|')return false;
            if(road[x][y] == '.')return false;
            break;
        case 2:
            if(road[x][y] == '-')return false;
            break;
        case 3:
            if(road[x][y] == '|')return false;
            if(road[x][y] == '.')return false;
            break;
        case 4:
            if(road[x][y] == '-')return false;
            if(road[x][y] == '.')return false;
            break;
    }
    return true;
}


int main()
{

    int start_x,start_y;
    int goal_x,goal_y;
    bool arr_goal[50][50] = {false};
    bool arr_start[50][50] = {false};
    int quearry_x[MAX];
    int quearry_y[MAX];
    int point_head,point_last;
    scanf("%d %d\n",&n,&m);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            {
                do {
                    scanf("%c", &road[i][j]);
                }while(road[i][j] == ' ' || road[i][j] == '\n');
                if(road[i][j] == 'S')
                {
                    start_x = i;
                    start_y = j;
                }
                if(road[i][j] == 'T')
                {
                    goal_x = i;
                    goal_y = j;
                }
            }
    point_head = 0;
    point_last = 1;
    quearry_x[point_head] = start_x;
    quearry_y[point_head] = start_y;
    arr_goal[start_x][start_y] = true;
    while(point_head < point_last)
    {
        int tmp_x = quearry_x[point_head],tmp_y = quearry_y[point_head];
        switch (road[tmp_x][tmp_y])
        {
            case 'S':
                if(is_inside(tmp_x - 1, tmp_y)&&!arr_goal[tmp_x - 1][tmp_y])
                {
                    arr_goal[tmp_x - 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x - 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y + 1)&&!arr_goal[tmp_x][tmp_y + 1])
                {
                    arr_goal[tmp_x][tmp_y + 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y + 1;
                    point_last++;
                }
                if(is_inside(tmp_x + 1, tmp_y)&&!arr_goal[tmp_x + 1][tmp_y])
                {
                    arr_goal[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y - 1)&&!arr_goal[tmp_x][tmp_y - 1])

                {
                    arr_goal[tmp_x][tmp_y - 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y - 1;
                    point_last++;
                }
                break;
            case 'T':
                if(is_inside(tmp_x - 1, tmp_y)&&!arr_goal[tmp_x - 1][tmp_y])
                {
                    arr_goal[tmp_x - 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x - 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y + 1)&&!arr_goal[tmp_x][tmp_y + 1])
                {
                    arr_goal[tmp_x][tmp_y + 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y + 1;
                    point_last++;
                }
                if(is_inside(tmp_x + 1, tmp_y)&&!arr_goal[tmp_x + 1][tmp_y])
                {
                    arr_goal[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y - 1)&&!arr_goal[tmp_x][tmp_y - 1])

                {
                    arr_goal[tmp_x][tmp_y - 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y - 1;
                    point_last++;
                }
                break;
            case '+':
                if(is_inside(tmp_x - 1, tmp_y)&&!arr_goal[tmp_x - 1][tmp_y])
                {
                    arr_goal[tmp_x - 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x - 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y + 1)&&!arr_goal[tmp_x][tmp_y + 1])
                {
                    arr_goal[tmp_x][tmp_y + 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y + 1;
                    point_last++;
                }
                if(is_inside(tmp_x + 1, tmp_y)&&!arr_goal[tmp_x + 1][tmp_y])
                {
                    arr_goal[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y - 1)&&!arr_goal[tmp_x][tmp_y - 1])

                {
                    arr_goal[tmp_x][tmp_y - 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y - 1;
                    point_last++;
                }
                break;
            case '-':
                if(is_inside(tmp_x, tmp_y + 1)&&!arr_goal[tmp_x][tmp_y + 1])
                {
                    arr_goal[tmp_x][tmp_y + 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y + 1;
                    point_last++;
                }
                if(is_inside(tmp_x, tmp_y - 1)&&!arr_goal[tmp_x][tmp_y - 1])

                {
                    arr_goal[tmp_x][tmp_y - 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y - 1;
                    point_last++;
                }
                break;
            case '|':
                if(is_inside(tmp_x - 1, tmp_y)&&!arr_goal[tmp_x - 1][tmp_y])
                {
                    arr_goal[tmp_x - 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x - 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_inside(tmp_x + 1, tmp_y)&&!arr_goal[tmp_x + 1][tmp_y])
                {
                    arr_goal[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                break;

            case '.':
                if(is_inside(tmp_x + 1, tmp_y)&&!arr_goal[tmp_x + 1][tmp_y])

                {
                    arr_goal[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                break;
        }
        point_head++;
    }
    point_head = 0;
    point_last = 1;
    quearry_x[point_head] = goal_x;
    quearry_y[point_head] = goal_y;
    arr_start[goal_x][goal_y] = true;
    while(point_head < point_last)
    {
        int tmp_x = quearry_x[point_head],tmp_y = quearry_y[point_head];
                if(is_outside(tmp_x - 1, tmp_y, 2)&&!arr_start[tmp_x - 1][tmp_y])
                {
                    arr_start[tmp_x - 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x - 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_outside(tmp_x, tmp_y + 1, 3)&&!arr_start[tmp_x][tmp_y + 1])
                {
                    arr_start[tmp_x][tmp_y + 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y + 1;
                    point_last++;
                }
                if(is_outside(tmp_x + 1, tmp_y, 4)&&!arr_start[tmp_x + 1][tmp_y])
                {
                    arr_start[tmp_x + 1][tmp_y] = true;
                    quearry_x[point_last] = tmp_x + 1;
                    quearry_y[point_last] = tmp_y;
                    point_last++;
                }
                if(is_outside(tmp_x, tmp_y - 1, 1)&&!arr_start[tmp_x][tmp_y - 1])
                {
                    arr_start[tmp_x][tmp_y - 1] = true;
                    quearry_x[point_last] = tmp_x;
                    quearry_y[point_last] = tmp_y - 1;
                    point_last++;
                }
        point_head++;
    }
    int sum = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(arr_goal[i][j]&&!arr_start[i][j])

            {
                sum++;
                //printf("%d %d\n",i,j);
            }


    if(!arr_goal[goal_x][goal_y])printf("I'm stuck!");
    else printf("%d",sum);
    return 0;
}
