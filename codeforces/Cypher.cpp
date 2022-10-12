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
        ll n; cin>>n;
        vec(v) inp
        loop(i, 0, n){
            ll moves; cin>>moves;
            string order; cin>>order;
            ll temp = 0;
            loop(j, 0, order.length()){
                if(order[j]=='D') temp++;
                else temp--;
            }
            if(temp >= 0){
                temp += v[i];
                temp %= 10;
                cout<<temp<<" ";
            }else{
                temp *= -1;
                if(temp < v[i]) cout<<v[i] - temp<<" ";
                else{
                    temp -= v[i];
                    cout<<(9-temp + 1)%10<<" ";
                }
            }
        }
        nl
    }
}