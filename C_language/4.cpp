//输入某年某月某日，判断这一天是这一年的第几天？
//
#include <stdio.h>
int main()
{
    int day, month, year;
    int monthday[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("enter by day month year!\n");
    scanf("%d %d %d",&day,&month,&year);
    bool isRunnian = false;
    if(year%400 == 0 || year%4 == 0 && year%100 != 0)isRunnian = true;
    int sum =0;
    for(int i = 0; i < month - 1; i++)
        sum += monthday[i];
    if(isRunnian)sum += day + 1;
    else sum += day;
    printf("%d",sum);
    return 0;
}