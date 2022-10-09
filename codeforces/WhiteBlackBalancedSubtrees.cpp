#include "bits/stdc++.h"
#include "unistd.h"
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define inp(v) for(ll i = 0; i < n; i++) cin>>v[i];
#define loop(i,st,n) for(ll i = st; i < n; i++)
#define vec(v) vector<ll> v(n);
#define vll vector<ll>
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define nl cout << "\n";
#define pb push_back
#define pr pair<ll, ll>
#define tc fast ll tp; cin>>tp; while(tp--)

pair<ll, ll> dfs(vector<bool> &vis, vector<vector<ll>> &adj, ll src, ll &ans, string s){
    vis[src] = 1;
    ll black = 0, white = 0;
    if(s[src-1] == 'W') white++;
    else black++;
    for(auto i: adj[src]){
        if(!vis[i]){
            pair<ll, ll> p = dfs(vis, adj, i, ans, s);
            black+=p.first;
            white+=p.second;
        }
    }
    if(black == white) ans++;
    return {black, white};
}

int main()
{
	tc{
        ll n; cin>>n;
        vector<ll> v(n+1);
        vector<bool> vis(n+1, 0);
        v[1] = 1; 
        loop(i, 2, n+1) cin>>v[i];
        string s; cin>>s;
        vector<vector<ll>> adj(n+1);
        loop(i, 1, n+1){
            adj[i].pb(v[i]);
            adj[v[i]].pb(i);
        }
        ll ans = 0;
        loop(i, 1, n+1){
            if(!vis[i]){
                dfs(vis, adj, i, ans, s);
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}