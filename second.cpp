#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
//  vector<int> v;

using namespace std;

typedef long long ll;
typedef unsigned long long ull;


int main() {
    
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin>>t;
    while(t--)
    {
    int arr[1001];
       int n;
       cin>>n;
       for (int i=0;i<n;i++)
       {
           cin>>arr[i];
       }
       sort(arr,arr+n);
       int y=0,max=0;
       for(int i=0;i<n-1;i++)
       {
           if(arr[i]==arr[i+1])
           {
               y++;
               if(max<y)
           {
               max=y;
           }
           }
           
           else
           {
               y=0;
           }
       }
       
       cout<<((n-max)-1)<<'\n';
       
    }
    
	return 0;
}
