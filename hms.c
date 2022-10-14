#include <stdio.h>
#include <stdlib.h>
int main()
{
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
      scanf("%d", &arr[i]);
    }
    int temp = arr[1];
    for(int i=0; i<n;i++)
    {
     if(temp>arr[i])
     temp = arr[i];
    }
    int ind;
    for(int i=0; i<n;i++)
    {
      if(arr[i]==temp)
      ind = i;
    }
    while(1)
    {
      if()
      if(i<(n-1))
      i=0;
    }
    printf("%d %d", temp, ind);
    
  }
  return 0;
}