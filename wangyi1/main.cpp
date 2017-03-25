#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int n,m;
    scanf("%d %d\n",&n,&m);
    int sum = 0;
    char a[2505];
    char b[2505];
    fgets(a,2505,stdin);
    fgets(b,2505,stdin);
    bool flg[5000] = {false};
    char *p;
    char *tmp;
    const char * split = " ";
    const char * split2 = "\n";
    p = strtok (a,split);
    while(p!=NULL) {
        if(p[strlen(p) - 1] == '\n')p[strlen(p) - 1] = '\0';
        if(strstr(b,p)){
            if(!flg[strstr(b,p) - b + 1]){
                sum += strlen(p) * strlen(p);
                flg[strstr(b,p) - b + 1] = true;
            }
        }
        p = strtok (NULL,split);
    }
    printf("%d",sum);
    return 0;
}