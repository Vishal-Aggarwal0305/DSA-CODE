#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(ll i = 0 ; i < n ; i++)
        {
            cin>>v[i];
        }
        ll l = 0, r = n-1;
        ll checker = INT_MIN, mn = INT_MAX;
        bool flag = 0;
        while(l <= r)
        {
            if(v[l]<=v[r])
            {
                if(v[l] < checker){
                    flag = 1;
                    break;
                }
                checker = max(checker,v[l]);
                l++;
            }
            else{
                if(v[r] < checker){
                    flag = 1;
                    break;
                }
                checker = max(checker,v[r]);
                r--;
            }
        }
        if(!flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}