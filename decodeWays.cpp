#include <bits/stdc++.h>
using namespace std;

int numDecode(string s, int n, vector<int> v){
    if(n== s.size()){
        return 1;
    }
    if(n == s.size()-1){
        return 1;
    }
    if(stoi(s.substr(n,1)) == 0){
        return 0;
    }
    int ways = numDecode(s, n+1, v);
    int ways2 = 0;

    if(stoi(s.substr(n,2)) <= 26){
        ways2 = numDecode(s, n+2, v);
    }

    return ways+ways2;
    
}

int main(){
    vector<int> v;
    string s = "1123";
    // int ans = numDecode(s, 0);
    // int n = stoi(s.substr(0, 1));
    // cout<<n;
    cout<<numDecode(s, 0, v);
    return 0;
}
