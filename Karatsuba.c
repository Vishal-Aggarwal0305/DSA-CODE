#include <stdio.h>
#include <string.h>
#include <math.h>
long int numlen(long long int t)
{
    int i = 0;
    while (t != 0)
    {
        t = t / 10;
        i++;
    }
    return i;
}

long long int power(long int s)
{

    if (s == 1)
    {
        return 10;
    }
    else
    {
        return 10 * power(s - 1);
    }
}
long long int karatsuba(long long int x, long long int y)
{
    long long int p = 0, x1, y1, x2, y2, u, v, w, z;
    long int n = numlen(x);
    long int n_y = numlen(y);
    if (n % 2 != 0)
    {
        n = n - 1;
    }
    if (x < 10 && y < 10)
    {
        p = x * y;
        return p;
    }
    else
    {
        long long int rem = power(n / 2);
        x1 = x / rem;
        y1 = y / rem;
        x2 = x % rem;
        y2 = y % rem;
        u = karatsuba(x1, y1);
        v = karatsuba(x2, y2);
        w = karatsuba(x1 - x2, y1 - y2);
        z = u + v - w;
        p = power(n) * u + power(n / 2) * z + v;
        return p;
    }
}

int main()

{
    long long int x, y;
    long long int c=0;

    printf("Enter the value of x ");
    scanf("%lld",&x);
    printf("Enter the value of y ");
    scanf("%lld",&y);
    c = karatsuba(x, y);
    printf("Result = %lld",c);
    return 0;
}