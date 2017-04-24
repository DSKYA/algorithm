#include <iostream>

int main() {

    int a[1005] = {0};
    bool b[1005] = {false};
    int n;
    int left = 0,right = 0;
    int tmp;
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&tmp);
        a[tmp]++;
        b[tmp] = true;
    }
    int head = 1,last = 1000;
    while(head < last)
    {
            while(!b[head])head++;
            while(!b[last])last--;
            if(head>= last)break;
            if(left <= right)
            {
                left += a[head];
                head++;
            }
            else
            {
                right += a[last];
                last--;
            }
    }
    if(right == left)printf("%d",head);
    else printf("-1");
    return 0;
}