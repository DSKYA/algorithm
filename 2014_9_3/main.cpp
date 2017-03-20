#include <iostream>
#include <string.h>
using namespace std;

void chzimu(char *s)
{
    int i = 0;
    while(i < strlen(s)){
        if(s[i] <= 'Z' && s[i] >= 'A'){
            s[i] = s[i] - 'A' + 'a';
        }
        i++;
    }
}

int main() {
    char st2[102];
    int flg;
    int n;
    cin>>st2>>flg>>n;
    //scanf("%s",st2);
    //scanf("%d",&flg);
    //scanf("%d",&n);
    if(!flg)chzimu(st2);
    for (int i = 0; i < n; ++i) {
        char tmp[102];
        char s[102];
        //scanf("%s",s);
        cin>>s;
        strcpy(tmp,s);
        if(flg){
            if(strstr(tmp,st2) != NULL)cout<<tmp<<endl;
        }
        else{
            chzimu(tmp);
            if(strstr(tmp,st2) != NULL)cout<<s<<endl;
        }
    }
    return 0;
}