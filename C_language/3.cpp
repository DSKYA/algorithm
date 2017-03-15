//
// 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多
//

#include "stdio.h"
#include "math.h"

int main()
{
    int i;

    for(i = sqrt(268); i < sqrt(100000) + 1; i++)
    {
        for(int j = i - 1; j >= 0; j--)
            if(i * i == j * j + 168)printf("%d\n",j * j - 100);
    }

    return 0;
}