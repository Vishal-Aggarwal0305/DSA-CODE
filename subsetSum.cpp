// author : Priyansh67

#include<bits/stdc++.h> 
using namespace std; 
                        
class Solution
{
    void solve(vector<int> &arr, vector<int> &ans,int i, int sum,int N) {
    if(i >= arr.size()) {
        ans.push_back(sum);
        return;
    }
    solve(arr, ans, i+1, sum+arr[i], N);
    solve(arr, ans, i+1, sum, N);
}
public:
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        solve(arr, ans, 0, 0, N);
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  