#include<bits/stdc++.h>
using namespace std;
class sol
{
    public:
    vector<int>maxSlidingWindow(vector<int>&nums,int k)
    {
        deque<int>dq;
        vector<int>ans;
        for(int i=0;i<nums.size();i++)
        {
        if(!dq.empty()&&dq.front()==i-k)
            dq.pop_front();
        while(!dq.empty()&&nums[dq.back()]<=nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
int main()
{
    sol s;
    vector<int>v;
    int n;
    cin>>n;
    int p;
    cin>>p;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int>k=s.maxSlidingWindow(v,p);
    for(int i=0;i<k.size();i++){
        cout<<k[i]<<" ";
    }
    return 0;
    
}