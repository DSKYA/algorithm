#include <stdio.h>
#define MAX 99999999999999

int main() {
    long long a[1002][1002];
    long long b[1002][1002];
    int n;
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        long long tmp;
        scanf("%lld",&tmp);
        a[i][i] = tmp;
        b[i][i] = tmp;
    }
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n - i; ++j) {
            long long max = MAX;
            b[j][j + i] = b[j][j + i - 1] + b[j + i][j + i];
            for (int k = 0; k < i; ++k) {
                long long sum = 0;
                sum += b[j][j + k];
                if(k > 0)sum += a[j][j + k];
                sum += b[j + k +1][j + i];
                if(k < i - 1)sum += a[j + k + 1][j + i];
                if(sum < max)max = sum;
            }
            a[j][j + i] = max;
        }
    }
    printf("%lld",a[1][n]);
    return 0;
}