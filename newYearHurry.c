#include <stdio.h>
int main ()
{
    int n,k,i,sum,res,c;
    while (scanf("%d %d", &n,&k))
    {
        res = 240 - k, sum = 0, c = 0;
        for (i=1; i<=n; i++)
        {
            sum += 5 * i;
            if (sum > res)
                break;
            c = c + 1;
        }
        printf("%d", c);
    }
    return 0;
}