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

vector<vector<ll>> rotateMat(vector<vector<ll>> v, ll n){
    vector<vector<ll>> aux(n, vector<ll> (n, 0));
    loop(i, 0, n){
        loop(j, 0, n){
            aux[j][i] = v[i][j];
        }
    }
    ll k = 0, l = n-1;
    loop(i, 0, n/2){
        loop(j, 0, n){
            swap(aux[j][k], aux[j][l]);
        }
        k++;
        l--;
    }
    return aux;
}

int main(){
    tc{
        ll n; cin>>n;
        vector<vector<ll>> v0(n, vector<ll> (n, 0)), v90(n, vector<ll> (n, 0)), v180(n, vector<ll> (n, 0)), v270(n, vector<ll> (n, 0));
        loop(i, 0, n){
            loop(j, 0, n){
                char ch; cin>>ch;
                v0[i][j] = ch - '0';
            }
        }
        v90 = rotateMat(v0, n);
        v180 = rotateMat(v90, n);
        v270 = rotateMat(v180, n);
        ll ans = 0;
        loop(i, 0, (n+1)/2){
            loop(j, 0, n/2){
                ll zero = 0, one = 0;
                (v0[i][j] == 0)?zero++:one++;
                (v90[i][j] == 0)?zero++:one++;
                (v180[i][j] == 0)?zero++:one++;
                (v270[i][j] == 0)?zero++:one++;
                ans += min(zero, one);
            }
        }
        cout<<ans<<"\n";
    }
}