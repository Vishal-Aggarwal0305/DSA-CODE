#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> nums{1,5,11,5};
    // cout<<nums[2];

    // considering a matrix with i and j
    // i is the total sum
    // j is the the number of elements present in array
    // which is(4) 0 -> 4 (1 extra)

    int n = nums.size();
    int sum = 0;
    for(auto x: nums){
        sum+=x;
    }
    cout<< sum;

    if(sum%2!=0){
        cout<<"Not Possible";
    }
    else{
        sum = sum/2;
        int dp[n+1][sum+1];
        for(int i = 0; i<sum+1; i++){
            dp[0][i] = false;
        }
        for(int i = 0; i<n+1; i++){
            dp[i][0] = true;
        }

        for(int i=1;i<n+1;i++)
            {
                for(int j=1;j<sum+1;j++)
                {
                    if(nums[i-1]>j)
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    {
                        dp[i][j]= dp[i-1][j] || dp[i-1][j-nums[i-1]];
                    }
                }
            }
            return dp[n][sum];    
    }

return 0;
}
