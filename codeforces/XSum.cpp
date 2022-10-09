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
        ll n, m, ans = LONG_LONG_MIN; cin >> n >> m;
        ll a[n][m];
		vector<ll> v(n + m + 1), v1(n + m + 1);
		loop(i, 0, n){
			loop(j, 0, m){
				cin >> a[i][j];
				v[i + j] += a[i][j];
				v1[i - j + m] += a[i][j];
			}
		}
		loop(i, 0, n)
			loop(j, 0, m)
				ans = max(ans, v[i + j] + v1[i - j + m] - a[i][j]);
		cout << ans << "\n";
    }
}