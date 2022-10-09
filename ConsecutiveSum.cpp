    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int main()
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll n,k;
            cin>>n>>k;
            vector<ll> v(n);
            for(ll i = 0 ; i < n ; i++)
            {
                cin>>v[i];
            }
            ll sum = 0;
            for(ll i = 0 ; i < k ; i++)
            {
                ll it = i;
                ll ans = INT_MIN;
                while(it < n)
                {
                    ans = max(ans,v[it]);
                    it += k;
                }
                sum += ans;
            }
            cout<<sum<<endl;
        }
    }