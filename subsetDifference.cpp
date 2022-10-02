#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v{1, 2, 7};
    int n = v.size(),sum = 0;
    for(auto x: v){
        sum+=x;
    }
    // cout<<sum;
    int dp[n+1][sum+1];

    // initialization
    for(int i=0; i<sum+1; i++){
        dp[0][i] = false;
    }

    for(int i=0; i<n+1; i++){
        dp[i][0] = true;
    }

    for(int i =1; i<n+1; i++){
        for(int j =1; j<sum+1; j++){
            if(v[i-1]>j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j] || dp[i-1][j-v[i-1]];
            }
        }
    }

    // for(int i =0; i<n+1; i++){
    //     for(int j =0; j<sum+1; j++){
    //         cout<<dp[i][j];
    //         // cout<<"hello";
    //     }
    //     cout<<endl;
    // }

    int diff = INT_MAX;
    for (int j = sum / 2; j >= 0; j--) {
        // Find the
        if (dp[n][j] == true) {
            diff = sum - 2 * j;
            break;
        }
    }
    cout<< diff;




    

return 0;
}
