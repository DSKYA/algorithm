//命令行选项
// Created by cxj on 17-3-16.
//

#include "stdio.h"
#include "string.h"

int main()
{
    char s[55];
    int letter[26] = {0};


    gets(s);
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        if(s[i + 1] == ':'){letter[s[i] - 'a'] = 2;i++;}
        else letter[s[i] - 'a'] = 1;
    }
    int n;
    scanf("%d\n",&n);
    for(int i = 1; i <= n; i++)
    {
        char tmp_s[258] ;
        gets(tmp_s);
        char last = '0';
        bool is_end = false;
        bool has_next = false;
        int j = 0;
        int num[26] = {0};
        bool is_on[26] = {false};
        while(tmp_s[j]!=' ')
        {
            if(tmp_s[j] == '\0')
            {
                is_end = true;
                break;
            }
            j++;
        }
        j++;
        while (!is_end)
        {
            char ss[258];
            int k = 0;
            while(tmp_s[j] !=' ' && tmp_s[j] != '\0')
            {
                ss[k] = tmp_s[j];
                k++;
                j++;
            }
            ss[k] = '\0';

            if(has_next)
            {
                if(last == '0')
                {
                    is_end = true;
                    break;
                }
                int sum = 0;
                for(int l = 0; l < strlen(ss); l++)
                {
                    if('0' <= ss[l] && ss[l] <= '9')
                    {
                        sum = sum * 10 + (ss[l] - '0');
                    }
                    else
                    {
                        is_end = true;
                        break;
                    }
                }
                if(!is_end)
                {
                    is_on[last - 'a'] = true;
                    num[last - 'a'] = sum;
                    has_next = false;
                }
            }
            else
            {
                if(ss[0] != '-' || strlen(ss) > 2 || !letter[ss[1] - 'a'])
                {
                    is_end = true;
                    break;
                }
                if(letter[ss[1] - 'a'] == 2)
                {
                    has_next = true;
                    last = ss[1];
                }
                else
                {
                    is_on[ss[1] - 'a'] = true;
                }
            }
            if(tmp_s[j] == '\0'){
                is_end = true;
            }
            j++;
        }
        printf("Case %d:",i);
        for(int l = 0; l < 26; l++)
        {
            if(is_on[l])
            {
                printf(" -");
                printf("%c",(l + 'a'));
                if(letter[l] == 2)
                {
                    printf(" ");
                    printf("%d",num[l]);
                }
            }
        }
        if(i != n)printf("\n");
    }
    return 0;
}