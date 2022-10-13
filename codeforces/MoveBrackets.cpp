#include <bits/stdc++.h>
#define endl  "\n"
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
int n;
   cin>>n;
   string s;
   cin>>s;
   int total=0,count=0;
   for(int i=0;i<n;i++){
    if(s[i]=='(')
    total++;
    if(s[i]==')')
    total--;
    if(total<0){
    count++;
    total=0;
    }
   }
   cout<<count<<endl;
   }
}
