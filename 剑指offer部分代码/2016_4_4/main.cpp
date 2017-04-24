#include<stdio.h>
#include<queue>
using namespace std;
struct State
{
    int x, y;
    int t;
};
struct Dead
{
    int l;
    int r;
};
Dead s[105][105] = {0};
State temp, now;
int flag[105][105][305] = {0}, dir[4][2] = {0,1,0,-1,1,0,-1,0};
queue<State> q;
int main(void)
{
    int i, n, m, t, x, y, l, r;
    scanf("%d%d%d", &n, &m, &t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d%d", &x, &y, &l, &r);
        s[x][y].l = l, s[x][y].r = r;
    }
    now.x = now.y = 1, now.t = 0;
    q.push(now);
    while(q.empty()==0)
    {
        now = q.front();
        q.pop();
        if(now.x==n && now.y==m)
            break;
        t = temp.t = now.t+1;
        for(i=0;i<=3;i++)
        {
            x = temp.x = now.x+dir[i][0];
            y = temp.y = now.y+dir[i][1];
            if(x>=1 && y>=1 && x<=n && y<=m && (t<s[x][y].l || t>s[x][y].r) && t<=300 && flag[x][y][t]==0)
                q.push(temp), flag[x][y][t] = 1;
        }
    }
    printf("%d\n", now.t);
    return 0;
}