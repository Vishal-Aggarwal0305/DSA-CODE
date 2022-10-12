#include <bits/stdc++.h>

using namespace std;
// Some typedef's
typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9 + 7;
const double eps = 1e-6;
const double pi = 1.00 * acos(-1.00);
#define IOS                  \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
typedef long long ll;
int main()
{
    IOS;
    int t;
    cin >> t;
    int cnt=0;
    while (t--)
    {
        string s;
        cin>>s;
        if(s[0]=='-'){
            cnt--;
        }
        else if(s[0]=='+'){
            cnt++;
        }
        else if(s[2]=='+'){
            cnt++;
        }
        else if(s[2]=='-'){
            cnt--;
        }
    }
    cout<<cnt;
    return 0;
}