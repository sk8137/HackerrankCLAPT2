#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int res[10000], k = 0;

void func(int x)
{
    int i, c = 0;
    for (i = 0; i <= k; i++)
    {
        res[i] = (res[i] * x) + c;
        c = res[i] / 10;
        res[i] = res[i] % 10;
    }
    while (c > 0)
    {
        k++;
        res[k] = c % 10;
        c = c / 10;
    }
    return;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, i;
        scanf("%d", &n);
        k = 0;
        res[k] = 1;
        for (i = 2; i <= n; i++)
        {
            func(i);
        }
        unsigned long long int s = 0;
        for (i = k; i >= 0; i--)
        {
            s = s + res[i];
        }
        printf("%llu\n", s);
    }
    return 0;
}