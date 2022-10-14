#include<stdio.h>
int main()
{
    int n,count=0;
    scanf("%d",&n);
    char st[n+1];
    scanf("%s",st);
    for(int i=0;i<n-1;i++)
    {
        if(st[i]==st[i+1])
        count++;
    }
    printf("%d\n",count);
    return 0;
}
