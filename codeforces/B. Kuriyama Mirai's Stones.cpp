#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n;cin>>n;long long a[n],b[n];
    long long sum_a[n+1]={0},sum_b[n+1]={0};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        sum_a[i+1]=sum_a[i]+a[i];
        b[i]=a[i];
    }
     sort(b,b+n);
     for(int i=0;i<n;i++)
     {
      sum_b[i+1]=sum_b[i]+b[i];
     }
    int m;cin>>m;
    while(m--)
    {
        int type,l,r;cin>>type>>l>>r;
        if(type==1)        
        cout<<sum_a[r]-sum_a[l-1]<<endl;        
        else
        cout<<sum_b[r]-sum_b[l-1]<<endl;
    }
       
}
