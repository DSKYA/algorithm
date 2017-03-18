#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;
#define maxn 1001
typedef long long LL;
struct Edge{
    int u,v,w;
}e[1000001];

bool cmp(Edge a,Edge b) {return a.w<b.w;}
int fa[maxn];
int Find(int x)
{
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}

bool Union(int x,int y)
{
    x=Find(x);
    y=Find(y);
    if(x==y) return 0;
    fa[x]=y;
    return 1;
}

int main()
{
    int i,m,n;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;++i) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    sort(e,e+m,cmp);
    int ans=0,tot=0;
    for(i=0;i<=n;++i) fa[i]=i;
    for(i=0;i<m;++i)
    {
        if(Union(e[i].u,e[i].v))
        {
            ans+=e[i].w;
            ++tot;
            if(tot==n-1) break;
        }
    }
    printf("%d\n",ans);
    return 0;
}
