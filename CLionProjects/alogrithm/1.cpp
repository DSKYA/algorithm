//
// 递归求1,2,3,4组合成无重复数字的3位数
//

#include<stdio.h>
bool a[4] = {false,false,false,false};
int b[3];

int dp(int i,int depth)
{
    b[depth] = i + 1;
    if(depth >= 2)printf("%d %d %d\n", b[0],b[1],b[2]);
    else
    {

        for(int j = 0; j < 4; j++)
        {
            if(!a[j])
            {
                a[j] = true;
                dp(j,depth + 1);
                a[j] = false;
            }
        }
    }
    return 0;
}

int main()
{
    for(int i = 0; i < 4; i++)
    {
        a[i] = true;
        dp(i,0);
        a[i] = false;
    }
}