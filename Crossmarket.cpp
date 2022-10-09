    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    int main()
    {
      ll t;
      cin >> t;
      while (t--)
      {
        ll n, m;
        cin >> n >> m;
        if(n == 1 && m == 1)
        {
          cout<<0<<endl;
          continue;
        }
        if(n == 1)
        {
          cout<<m<<endl;
          continue;
        }
        if(m == 1)
        {
          cout<<n<<endl;
          continue;
        }
        ll ans = 0;
        int maxi = max(n,m);
        int mini = min(n,m);
        ans = 2*(mini-1)+maxi;
        cout<<ans<<endl;
      }
    }