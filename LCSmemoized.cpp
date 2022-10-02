#include <bits/stdc++.h>
using namespace std;



int lcs(string s1, string s2, int n, int m, vector<vector>> dp){
    if(n == 0 || m == 0){
        return 0;
    }

    if(dp[n][m]!=-1){
        return dp[n][m];
    }

    if(s1[n-1]==s2[m-1]){
        return dp[n][m] =  1+lcs(s1, s2, n-1, m-1);
    }
    else{
        return dp[n][m] = max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
    }
}

int main(){
    // 
    vector<vector> dp(n+1,vector(m+1,-1))
    string s1 = "ylqpejqbalahwr";
    int n = s1.size();
    string s2 = "yrkzavgdmdgtqpg";
    int m = s2.size();
    // cout<<n<<m;
    memset(dp, -1, sizeof(dp));

    
    
    cout<<lcs(s1, s2, n, m, dp);

return 0;
}
