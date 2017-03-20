//
// Created by cxj on 17-3-15.
// 判断101-200之间有多少个素数，并输出所有素数

#include "stdio.h"

int main()
{
    bool isSushu = false;
    for(m=101;m<=200;m++) {
        is Sushu = true;
        k = sqrt(m + 1);
        for (i = 2; i <= k; i++)
            if (m % i == 0) {
                isSushu = false;
                break;
            }
    }
    return 0;
}

