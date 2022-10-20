
#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
// for finding length of number
ll numlen(ll t)
{
    int i = 0;
    while (t != 0)
    {
        t = t / 10;
        i++;
    }
    return i;
}
// for finding 10 to the power of number
ll power(ll s)
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

ll karatsuba(ll x, ll y)
{
    ll p = 0, div1, div2, div3, div4, u, v, w, z;
    ll n = numlen(x);
    ll n_y = numlen(y);

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
       
        ll div1 = power(n / 2);

        div1 = x / div1;
        div2 = y / div1;

        div3 = x % div1;
        div4 = y % div1;

       

        u = karatsuba(div1, div2);
        v = karatsuba(div3, div4);
        w = karatsuba(div1 - div3, div2 - div4);

        z = u + v - w;
        p = power(n) * u + power(n / 2) * z + v;
        return p;
    }
}

int main()

{
    ll x, y;
   cin>>x>>y;
   cout<< karatsuba(x,y);
    return 0;
}