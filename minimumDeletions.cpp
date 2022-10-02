#include <bits/stdc++.h>
using namespace std;

int main(){
    string word1 = "sea", word2 = "eat";
    // cout<<word1;

    int n = word1.size();
    int m = word2.size();

    // cout<<n<<m;
    int dp[n+1][m+1];

    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
        // dp[0][i] = 0;
    }

    for(int j = 0; j<=m; j++){
        dp[0][j] = 0;
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            // cout<<dp[i][j];
            if(word1[i-1]==word2[j-1]){
                dp[i][j]= 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }

        }
        // cout<<endl;
    }
    // cout<<dp[n][m];

    

    int deletion = n - dp[n][m];
    cout<<deletion;
    int addtition = m- dp[n][m];
    cout<<addtition;
    cout<<deletion+addtition;



    return 0;
}
