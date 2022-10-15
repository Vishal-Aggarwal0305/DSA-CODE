#include<bits/stdc++.h>
using namespace std;
int main()
{ 
    int c=0;
    int n;cin>>n;string s;cin>>s;
    string s3[n-1];
    for(int i=0;i<n-1;i++)
    {
        string s2=s.substr(i,2);
        s3[i]=s2;
    }
    map<string,int>m;
    for(int i=0;i<n-1;i++)
    m[s3[i]]++;
    vector<pair<int,string>>vp;  
    for(auto it:m)
    {
    vp.push_back( make_pair(it.second,it.first ));
    }
    int x=vp.size();
    sort(vp.begin(), vp.end());
     cout << vp.back().second << endl;

}
