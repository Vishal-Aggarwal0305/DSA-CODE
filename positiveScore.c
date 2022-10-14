#include <stdio.h>
#include <string.h>

int main()
{
    int n,k;
    scanf("%d %d", &n , &k);
    int arr[n];
    int count = 0;
    for(int i = 1;i<=n;i++)
    scanf("%d", &arr[i]);
    for(int m = 1;m<=n;m++)
    {
        if(arr[m]>=arr[k] && arr[m]>0)
        count++;
    }
    printf("%d", count);
    
}