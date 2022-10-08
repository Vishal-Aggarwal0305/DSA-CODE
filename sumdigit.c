#include <stdio.h>

#include <stdio.h>

int main()
{
    int a,n,rem,summ;
    printf("Enter any number");
    scanf("%d",&a);
    rem=0,summ=0;
    
    while(a>0)
    {
    rem=(a%10);
    a=a/10;
    summ=summ+rem;
    }
    printf("The sum is %d",summ);
    return 0;
}
