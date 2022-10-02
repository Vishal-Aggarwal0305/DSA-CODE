#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "leetcode";
    // edocteel
    string b = s;
    reverse(s.begin(), s.end());
    // cout<<s;
    int n = s.size();
    int m = b.size();

    int dp[n+1][m+1];
    for(int i = 0; i<= n; i++){
        dp[i][0] = 0;
    }

    for(int i = 0; i<= m; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            // cout<<dp[i][j];
            if(s[i-1]==b[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            // if(s[i-1]==b[j-1]){
                // dp[i][j] = 1+ dp[i-1][j-1];
            // }
            // else{
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            // }
        }
        // cout<<endl;
    }
    // cout<<dp[n][m];
    cout<< n-dp[n][m];

    


    return 0;
}
