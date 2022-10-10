#include<bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin>>t;
    string a="yes";
    while(t--)
    {
        string s;
        cin>>s;
        transform(s.begin(),s.end(),s.begin(), ::tolower);
        if(s==a)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
return 0;
}