    #include <iostream>

    int main() {
        long t1 = 0;
        long t2;
        int n;
        long max = -1;
        scanf("%d",&n);
        for (int i = 0; i < n; ++i) {
            scanf("%ld",&t2);
            if(i != 0)
            {
                long tmp;
                if((t2 - t1) > 0)tmp = t2 - t1;
                else tmp = t1 - t2;
                if(tmp > max)max = tmp;
            }
            t1 =t2;
        }
        printf("%ld",max);
        return 0;
    }