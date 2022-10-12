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
        unordered_set<string> s;
        vector<string> v(n);
        loop(i, 0, n){
            cin>>v[i];
            s.insert(v[i]);
        }
        loop(i, 0, n){
            string str = v[i], temp1 = "", temp2 = "";
            ll k = 1;
            loop(j, 0, str.length()){
                temp1 = str.substr(0, j+1);
                temp2 = str.substr(j+1, str.length() - j);
                if(s.find(temp1) != s.end() && s.find(temp2) != s.end()){
                    cout<<1;
                    k = 0;
                    break;
                }
            }
            if(k==1) cout<<0;
        }
        nl
    }
}