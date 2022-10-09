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
        string s; cin>>s;
        ll s1 = 0, s2 = 0;
        loop(i, 0, 6){
            if(i<=2) s1 += (s[i]-'0');
            else s2 += (s[i]-'0');
        }
        cout<<((s1==s2)?"yes\n":"no\n");
    }
}