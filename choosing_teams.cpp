#include<bits/stdc++.h>

using namespace std;
int main()
{
    int c=0,n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if((5-a[i])>=k)
        {
            c++;
        }
    }
        int b=c/3;
        if(b>=1)
        {
            cout<<b;
        }
        else{
            cout<<0;
        }
return 0;
}