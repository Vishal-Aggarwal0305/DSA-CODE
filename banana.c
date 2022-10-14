#include <stdio.h>
int main()
{
    int k,n,w;
    scanf("%d %d %d", &k,&n,&w);
    int sum = 0;
    for(int i = 1;i<=w;i++)
    sum  =  sum + i*k;
    if(sum<=n)
    printf("0");
    if(sum>n)
    printf("%d", (sum-n));
    return 0;

}