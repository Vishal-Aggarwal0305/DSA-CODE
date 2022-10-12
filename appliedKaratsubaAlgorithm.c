#include <stdio.h>

long long power(long s)
{
    long result=1;
    int i;
    for(i=0; i<s; i++)
	{
        result=result*10;
    }
    return result;
}

long long numlen(long t)
{
    int count=0;
    while(t!=0)
	{
        count++;
        t=t/10;
    }
    return count;
}

long long karatsuba(long long x, long long y)
{
    long long n,x1,x2,y1,y2,u,v,w,z,p;
	n=numlen(x);
 
    if(n==1)
	{
        p=x*y;
    }
    else
	{
        x1=x/(power(n/2));
        x2=x%power(n/2);
        y1=y/(power(n/2));
        y2=y%power(n/2);
        u=karatsuba(x1,y1);
        v=karatsuba(x2,y2);
        w=karatsuba(x1-x2,y1-y2);
        z=u+v-w;
        p=(power(n)*u)+(power(n/2)*z)+v;
    }
    
    return p;
}

int main()
{
    long long x,y,r;
    printf("X : ");
    scanf("%lld",&x);
    printf("Y : ");
    scanf("%lld",&y);
 
    r = karatsuba(x,y);
    printf("\nX*Y=%lldx%lld=%lld",x,y,r);
    
    return 0;
}
