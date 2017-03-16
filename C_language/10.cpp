//ISBN号码
// Created by cxj on 17-3-16.
//

#include "stdio.h"
#include "string.h"

int num(char c)
{
    if(c == 'X')return 10;
    int answer = c - '0';
    //printf("%d ",answer);
    return answer;
}

char lett(int i)
{
    if(i == 10)return 'X';
    else return i + '0';
}

int main()
{
    char isn[15];
    scanf("%s",isn);
    long long sum = 0;
    sum += num(isn[0])*1;
    sum += num(isn[2])*2;
    sum += num(isn[3])*3;
    sum += num(isn[4])*4;
    sum += num(isn[6])*5;
    sum += num(isn[7])*6;
    sum += num(isn[8])*7;
    sum += num(isn[9])*8;
    sum += num(isn[10])*9;
   // printf("\n%d",sum);
    sum = sum % 11;
    if(sum == num(isn[12]))printf("Right");
    else
    {
        isn[12] = lett(sum);
        printf("%s",isn);
    }
    return 0;
}