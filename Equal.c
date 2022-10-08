#include <stdio.h>
#include <math.h>
int main()
{
    int a,b;

    printf("Enter two number:");
    scanf("%d,%d",&a,&b);
    //if ((a & ~b) == 0 && (~a & b) == 0) 
     if( a-b== 0 ) 
        printf("Numbers are equal");
    else
         printf("Numbers are not equal");
    return 0;
}
