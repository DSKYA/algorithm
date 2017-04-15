#include<stdio.h>
int AddDiagonal(int a[10][10], int n)
{
    int i,j;
    int sum=0;
    for(i=0;i<n;i++)
    {
        sum=sum+a[i][i];
        sum=sum+a[i][n-i-1];
    }
    return sum;
}

void InputMatrix(int a[10][10], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}


int main()
{
    int n;
    int sum;
    int a[10][10];
    printf("Input n:");
    scanf("%d",&n);
    printf("Input %d*%d matrix:\n",n,n);
    InputMatrix(a,n);
    sum=AddDiagonal(a,n);
    printf("sum = %d\n",sum);
    return 0;
}

