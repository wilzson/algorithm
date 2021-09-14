#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const char* mahjong[] = {"1p", "2p", "3p", "4p", "5p", "6p", "7p", "8p", "9p",
    "1s", "2s", "3s", "4s", "5s", "6s", "7s", "8s", "9s",
    "1m", "2m", "3m", "4m", "5m", "6m", "7m", "8m", "9m",
    "dong", "nan", "xi", "bei",
    "zhong", "fa", "bai"
};   //指针数组
int c[34];

int convert(char *s)
{
    for (int i = 0; i < 34; i++)
        if (strcmp(mahjong[i],s) == 0)
            return i;
    return -1;
}

bool search(int t)
{
    for (int i = 0; i < 34; i++)
        if (c[i] >= 3)
        {
            if (t == 3)
                return true;
            c[i] -= 3;
            if (search(t+1))
                return true;
            c[i] += 3;
        }

    for (int i = 0; i <= 24; i++)
        if (i % 9 <= 6 && c[i] >= 1 && c[i+1] >= 1 && c[i+2] >= 1)
        {
            if (t == 3)
                return true;
            c[i]--,c[i+1]--,c[i+2]--;
            if (search(t+1))
                return true;
           c[i]++,c[i+1]++,c[i+2]++;
        }
    return false;
}

bool check()
{
    for (int i = 0; i < 34; i++)
    {
        if (c[i] >= 2)
        {
            c[i] -= 2;
            if (search(0))
                return true;
            c[i] += 2;
        }
    }
    return false;
}

int main()
{
    int cas = 0;
    bool ok;
    char s[100];
    int majiang[15];

    while (scanf("%s",s) != EOF)
    {
        if (s[0] == '0')
            break;
        majiang[0] = convert(s);
        for (int i = 1; i < 13; i++)
        {
            scanf("%s",s);
            majiang[i] = convert(s);
        }
        ok = false;
        for (int i = 0; i < 34; i++)
        {
            memset(c,0,sizeof(c));
            int j;
            for (int j = 0; j < 13; j++)
                c[majiang[j]]++;
            if (c[i] >= 4)
                continue;
            c[i]++;
            if (check())
            {
                ok = true;
                printf("%s ",mahjong[i]);
            }
            c[i]--;
        }
        if (!ok)
            printf("Not ready");
        printf("\n");
    }
    return 0;

}
