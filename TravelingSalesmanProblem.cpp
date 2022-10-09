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
            ll ny=0, py = 0, nx = 0, px = 0;
            ll x,y;
            while(n--)
            {
                cin>>x>>y;
                if(x == 0 && y == 0) continue;
                else if(x == 0)
                {
                    if(y<0)
                    {
                        ny = max(ny,abs(y));
                    }
                    else
                    {
                        py = max(py,abs(y));
                    }
                }
                else if(y == 0)
                {
                    if(x<0)
                    {
                        nx = max(nx,abs(x));
                    }
                    else
                    {
                        px = max(px,abs(x));
                    }
                }
            }
            cout<<2*(nx+ny+px+py)<<endl;
        }
    }

