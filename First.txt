#include<iostream>
#include<typeinfo>
#include<iomanip>
#include<string>
#include <algorithm>
#include<cmath>
#include <chrono>
#include <ctime>
#include<vector>
#include<set>
#include<queue>
#include<list>
#include<map>
#include<stack>
#include <unordered_map>
#include <unordered_set>
#define SQ(a) (a)*(a)
using namespace std;
typedef long long int ll;
using vi = vector<int>;
using vl = vector<ll>;
using vc = vector<char>;
#define ENDL "\n";
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define forn(n) for (int i = 0; i < int(n); i++)
#define FAST ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

bool isprime(ll x)
{
    if (x == 2)
        return 1;
    if (x == 1)
        return 0;
    ll lim = sqrt(x);
    for (int i = 2; i <= lim; i++)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}
int frequancy(int num)
{
    int n;
    cin >> n;
    vector<int>v(n);
    int arr[100] = { 0 };
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        arr[v[i]]++;
    }
    return arr[num];
}
ll fact(ll num)
{
    if (num == 0 || num == 1)
        return 1;
    else
        return num * fact(num - 1);
}
bool ispalindrom(int num)
{
    int x = num,x2=0;
    while (num != 0)
    {
        x2 = num % 10;
        num /= 10;
    }
    if (x == x2)
        return true;
    else
        return false;
}

// ==============================================================
/*int n;
cin >> n;
vector<int>v(n);
deque<int>d;
for (int i = 0; i < n; i++) {
	cin >> v[i];
	d.push_back(v[i]);
}
if (n % 2 != 0)
	n++;
for (int i = 0; i < n / 2; i++)
{
	if (d.size() == 1)
	{
		cout << d.front();
		return 0;
	}
	cout << d.front() << " ";
	d.pop_front();
	cout << d.back() << " ";
	d.pop_back();
}*/

ll divSum(ll num)
{
    ll sum = 0;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            if (i == (num / i))
                sum += i;
            else
                sum += (i + num / i);
        }
    }
    return sum;
}
ll GCD(ll x, ll y)
{
    if (x < y)
        swap(x, y);
    while (x != 0 && y != 0)
    {
        ll res = x % y;
        x = y;
        y = res;
    }
    return x;
}
ll LCM(ll x, ll y)
{
    return x / GCD(x, y) * y;
}
void prefix_Sum(int n, int m)
{
    ll arr[101];
    ll p[101] = { 0 };
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        p[i] = arr[i] + p[i - 1];
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        cout << p[r] - p[l - 1] << "\n";
    }
}
bool binarySearch(vector<int> v, int To_Find)
{
    int low = 0, high = v.size()-1, mid=0;
    while (high - low > 1)
    {
        mid = (high + low) / 2;
        if (v[mid] < To_Find)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    if (v[low] < To_Find)
    {
        low = mid + 1;
    }
    else
    {
        high = mid;
    }
    if (v[low] == To_Find)
        return true;
    else if (v[high] == To_Find)
        return true;
    else
        return false;
}
ll sum(ll n) // the of the numbers from 1 to n
{
    return n * (n + 1) / 2;
}
bool isInt(double num)
{
    if (floor(num) == ceil(num))
        return true;
}
bool isPowerOfTwo(int x)
{
    return x && (!(x & (x - 1)));
}
ll Sum_Odd(ll x)
{
    ll result = pow((x + 1) / 2, 2);
    return result;
}
/*int mx(vector<int>a)
{
    int res = INT_MIN;
    for (auto i : a)
        res = max(res, i);
    return res;
}
int mxx(int n,int arr[101])
{
    int res = INT_MIN;
    for (int i=0; i<n; i++)
        res = max(res, arr[i]);
    return res;
}*/
/*int mn(vector<int>a)
{
    int res = INT_MAX;
    for (auto i : a)
        res = min(res, i);
    return res;
}*/
// log2(n) => cout << floor(log2(n));
int remove0(int n)
{
    ll m=0, pow=1;
    while (n != 0)
    {
        int d = n % 10;
        n /= 10;
        if (d != 0)
        {
            m += d * pow;
            pow *= 10;
        }
    }
    return m;
}
/*int  n,m;
cin>>n>>m;
int arr[m+1];
vi v(n);
bool flag =1;
for(int i=0;i<n;i++)
{
    cin>>v[i];
    arr[v[i]]++;
}
for(int i=0;i<m;i++)
{
    if(arr[i]%(i+1)!=0)
    {
        flag=0;
        break;
    }
    else{
        arr[i+1]+=arr[i]/(i+1);
    }
}
if(flag==1)
    cout<<"Yes\n";
else
    cout<<"No\n";*/

int main()
{
    FAST
    int t;
    cin>>t;
    int sum1=0,sum2=0,lead=0,win=0;
    while(t--)
    {
        int l1,l2;
        cin>>l1>>l2;
        sum1+=l1;
        sum2+=l2;
        if((lead<abs(sum1-sum2))&&(sum1-sum2)>0)
        {
            lead=abs(sum1-sum2);
            win=1;
        }
        if((lead<abs(sum1-sum2)) && (sum1-sum2)<0)
        {
            lead=abs(sum1-sum2);
            win=2;
        }
    }
        cout<<win<<" "<<lead;
}
