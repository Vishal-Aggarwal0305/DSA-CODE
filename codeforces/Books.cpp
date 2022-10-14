#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n,k;
  cin>>n>>k;
  int a[n];
  for(int i=0;i<n;i++)cin>>a[i];
    int sum=0,l=0,ans=0;
  for(int r=0;r<n;r++){
    sum+=a[r];
        while(sum>k){
       sum-=a[l];
       l++;
    }
    if(sum<=k){
        ans=max(ans,r-l+1);
    }
  }
  cout<<ans;
}
