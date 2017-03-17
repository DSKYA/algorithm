#include <iostream>

int main() {
    int n;
    bool a[101]= {false};
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        int tmp;
        scanf("%d",&tmp);
        bool is_lian = false;
        for (int j = 0; j < 100 / 5 && !is_lian; ++j) {
            int k = 1;
            int sum = 0;
            while(k <= 5 && !is_lian)
            {
                int head;
                while(a[j * 5 + k] && k <= 5)k++;
                if(k > 5)break;
                head = k + j * 5;
                sum = 0;
                while(!a[j * 5 + k] && k <= 5 && sum < tmp)
                {
                    sum++;
                    k++;
                }
                if(sum == tmp)
                {
                    is_lian = true;
                    for (int l = 0; l < tmp; ++l) {
                        printf("%d ",l + head);
                        a[l + head] = true;
                    }
                    break;
                }
            }
        }
        if(!is_lian)
        {
            for (int j = 1; j <= 100 && tmp > 0 ; ++j) {
                if(!a[j])
                {
                    a[j] = true;
                    printf("%d ",j);
                    tmp--;
                }
            }
        }
        if(i < n - 1)printf("\n");
    }
    return 0;
}