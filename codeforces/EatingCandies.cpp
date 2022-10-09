#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int s[n];
        for(int i=0; i<n; i++){
            cin>>s[i];
        }
        int i=0, j=n-1, x=-1;
        int a=s[i], b=s[j];
        while(i<j){
            if(a>b){
                j--;
                b+=s[j];
            }
            else if(b>a){
                i++;
                a+=s[i];
            }
            else if(a==b){
                x=i+1+(n-j);
                i++; j--;
                a+=s[i];
                b+=s[j];
            }
        }
        if(x==-1)cout<<0<<endl;
        else cout<<x<<endl;
        
    }
    return 0;
}