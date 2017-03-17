#include <iostream>

double shuihou(double s)
{
    double a;
    a = s - 3500;
    double sum = 0;
    if(a <= 0)return s;
    else
    {
        if(a >= 1500)
        {
            sum += 1500 * 0.03;
            if(a >= 4500)
            {
                sum += (4500 - 1500) * 0.1;
                if(a >= 9000)
                {
                    sum += 4500 * 0.2;
                    if(a >= 35000)
                    {
                        sum += (35000 - 9000) * 0.25;
                        if(a >= 55000)
                        {
                            sum += (55000 - 35000) * 0.3;
                            if(a >= 80000)
                            {
                                sum += (80000 - 55000) * 0.35;
                                sum += (a - 80000) * 0.45;
                            }
                            else sum +=(a - 55000) * 0.35;
                        }
                        else sum += (a - 35000) * 0.3;
                    }
                    else sum += (a - 9000) * 0.25;
                }
                else sum += (a - 4500) * 0.2;
            }
            else sum += (a - 1500) * 0.1;
        }
        else sum += a * 0.03;
    }
    return s - sum;
}

int main() {
    int m;
    scanf("%d",&m);
    int i = m;
    while(true)
    {
        if((int)shuihou((double)i) == m)break;
        else i++;
    }
    printf("%d",i);
    return 0;
}