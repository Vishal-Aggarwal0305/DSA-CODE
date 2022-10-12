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
        ll n, k; cin>>n>>k;
        vec(v) inp
        ll ans = 0, temp = 0;
        loop(i, -1, n){
            ll curr = temp;
            loop(j, i+1, min(n, i+33)){
                ll temp1 = v[j];
                temp1>>=(j-i);
                curr += temp1;
            }
            ans = max(ans, curr);
            if( i < n) temp += (v[i+1] - k);
        }
        cout<<ans<<"\n";
    }
}