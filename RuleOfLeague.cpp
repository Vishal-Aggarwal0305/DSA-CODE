    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
     
    int main()
    {
        ll t;
        cin>>t;
        while(t--)
        {
            ll n,x,y;
            cin>>n>>x>>y;
            bool flag = 0;
            if((x == 0 && y == 0) || (x != 0 && y != 0)){
                cout<<"-1"<<endl;
                continue;
            } 
            ll temp = x+y;
            if((n-1)%temp != 0){
                cout<<"-1"<<endl;
                continue;
            } 
            ll k = (n-1)/temp;
            ll temp1 = k;
            ll i = 1;
            while(temp1--)
            {
                ll temp2 = temp;
                while(temp2--)cout<<i<<" ";
                if(i == 1) i += temp+1;
                else i += temp;
            }
            cout<<endl;
        }
    }