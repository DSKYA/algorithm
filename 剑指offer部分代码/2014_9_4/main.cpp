#include <iostream>
#include <queue>

#define MAX 99999999

using namespace std;

struct node
{
    int x,y;
    long long cost;
};


struct clnode
{
    int x,y;
    long long num;
};

int main() {
    int n,m,k,d;
    bool fobid[1002][1002] = {false};
    scanf("%d %d %d %d",&n,&m,&k,&d);
    int bhx[4] = {0,1,0,-1};
    int bhy[4] = {1,0,-1,0};
    long long sum = 0;
    node bsn;
    queue<node> q;
    long long costmin[1002][1002];
    bsn.cost = 0;
    bool ar[1002][1002] = {false};
    for (int i = 0; i < m; ++i) {
        scanf("%d %d",&bsn.x,&bsn.y);
        q.push(bsn);
        ar[bsn.x][bsn.y] = true;
    }
    clnode cln[1000000];
    for (int j = 0; j < k; ++j) {
        scanf("%d %d %lld",&cln[j].x,&cln[j].y,&cln[j].num);
    }
    for (int l = 0; l < d; ++l) {
        int tmx,tmy;
        scanf("%d %d",&tmx,&tmy);
        fobid[tmx][tmy] = true;
    }
    node tmp;
    while(!q.empty()){
            tmp = q.front();
            q.pop();
            for (int j = 0; j < 4; ++j) {
                int tmx = tmp.x + bhx[j];
                int tmy = tmp.y + bhy[j];
                if(tmx <= n && 1 <= tmx && tmy <= n && 1 <= tmy && !ar[tmx][tmy] && !fobid[tmx][tmy]){
                    node t;
                    t.x = tmx;
                    t.y = tmy;
                    t.cost = tmp.cost + 1;
                    ar[tmx][tmy] = true;
                    costmin[tmx][tmy] = t.cost;
                    q.push(t);
                }
            }
        }
    for (int o = 0; o < k; ++o) {
        sum += costmin[cln[o].x][cln[o].y] * cln[o].num;
    }
    printf("%lld",sum);
    return 0;
}