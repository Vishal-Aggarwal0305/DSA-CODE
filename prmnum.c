#include <stdio.h>

int main()
{
    int i=2, n,r=0;
    printf("Enter your Number:");
    scanf("%d",&n);
    
    label:
        if(i<n)
        {
            if(n%i==0)
            {
                r=1;
            }
            i=i+1;
            goto label;
        }
        if(r==1)
            printf("\nNumber is not prime");
        else
            printf("\nNumber is prime");

    return 0;
}
