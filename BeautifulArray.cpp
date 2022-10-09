    #include <bits/stdc++.h>
    using namespace std;
     
    #define ll long long
    int main()
    {
      ll t;
      cin >> t;
      while (t--)
      {
        ll n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s < (k * b))
        {
          cout << -1 << endl;
        }
        else if (s / k == b)
        {
          cout << s << " ";
          n--;
          while (n)
          {
            cout << "0 ";
            n--;
          }
          cout << endl;
        }
        else if ((((k * (b + 1)) - 1) + ((n - 1) * (k - 1))) < s)
        {
          cout << "-1"<<endl;
        }
        else
        {
          ll sum = (k * (b + 1)) - 1;
          cout << sum << " ";
          n--;
          // cout<<"n: "<<n<<endl;
          while (sum <= s && n)
          {
            if (sum + k - 1 <= s){
              cout << k - 1 << " ";
              n--;
              sum += k - 1;
            }
            else break;
          }
          // cout<<"n: "<<n<<endl;
          if (sum != s && n)
          {
            cout << s - sum << " ";
            n--;
          }
          // cout<<"n: "<<n<<endl;
          while (n--)
          {
            cout << "0 ";
          }
          cout << endl;
        }
      }
    }