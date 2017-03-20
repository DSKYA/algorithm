//流问题

#include <iostream>
using namespace std;

struct node{
    int cl;
};

int rl[101];
int bc[101];
bool ym[101];
int now_cl[101] = {0};
int e[101][101];

int main() {
    int n,m;
    cin>>n>>m;
    node alc[101][8];
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            if(i == j)e[i][j] = 0;
            else{
                e[i][j] = 999999;
                e[j][i] = 999999;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 16; ++j) {
            int tmp;
            cin>>tmp;
            if(j <= 7)alc[i][j].cl = tmp;
            else if(j <= 14)alc[i][j - 7].cl = -tmp;
            else if(j == 15)rl[i] = tmp;
            else bc[i] = tmp;
        }
    }
    return 0;
}