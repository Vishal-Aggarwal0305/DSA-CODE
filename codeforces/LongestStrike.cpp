#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inp for(ll i = 0; i < n; i++) cin>>v[i];
#define loop(i,st,n) for(ll i = st; i < n; i++)
#define vec(v) vector<ll> v(n);
#define vll vector<ll>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl cout << "\n";
#define pb push_back
#define pr pair<ll, ll>
#define tc fast ll t; cin>>t; while(t--)

int main(){
    tc{
        ll n, k, x; cin>>n>>k;
        map<ll, ll> m;
        loop(i, 0, n){
            cin>>x;
            m[x]++;
        }
        if(n==1 && k != 1 || k > n){
            cout<<-1<<"\n";
            continue;
        }
        vector<ll> v;
        for(auto i: m){
            if(i.second>=k) v.pb(i.first);
        }
        ll temp = LONG_LONG_MIN, ind1=-1, ind2=-1, i = 1, diff, a = -1, b = -1, op = 0;
        while(i < v.size()){
            if(v[i]-v[i-1]==1){
                ind1 = v[i-1];
                while(v[i]-v[i-1]==1 && i < v.size()){
                    i++;
                }
                ind2 = v[i-1];
                diff = ind2 - ind1;
                op = 1;
            }
            if(diff>temp && op == 1){
                temp = diff;
                a = ind1;
                b = ind2;
            }
            i++;
        }
        if(a==-1 && b==-1){
            if(v.size()>0) cout<<v[0]<<" "<<v[0]<<"\n";
            else cout<<-1<<"\n";
        }else cout<<a<<" "<<b<<"\n";
    }
    return 0;
}