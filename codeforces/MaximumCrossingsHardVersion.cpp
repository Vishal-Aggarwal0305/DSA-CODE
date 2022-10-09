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
ll a[200005],f[200005],n;

int main()
{
	tc{
		ll ans=0; cin>>n;
		loop(i, 1, n+1)  cin>>a[i];
        loop(i, 1, n+1) f[i] = 0;
		for(ll i=n;i>=1;i--){
		    for(ll j=a[i];j>0;j-=j&(-j)) ans+=f[j];
		    for(ll j=a[i];j<=n;j+=j&(-j)) f[j]++;
		}
        cout<<ans<<"\n";
	}
	return 0;
}