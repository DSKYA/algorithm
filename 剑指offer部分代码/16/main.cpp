//相反数
#include <iostream>

int main() {
    int a[1005]= {0};
    int n;
    int tmp;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&tmp);
        if(tmp < 0)a[-tmp]++;
        else a[tmp]++;
    }
    int sum = 0;
    for(int i = 0; i <= 1000; i++)
    {
        if(a[i] == 2)sum++;
    }
    printf("%d",sum);
    return 0;
}