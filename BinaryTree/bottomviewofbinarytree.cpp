
class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>>q;int line=0;
        pair<Node*,int>p;p.first=root;p.second=line;
        vector<int>l;q.push(p);
        map<int,int>mp;
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            if(mp.find(it.second)==mp.end() ||mp.find(it.second)!=mp.end())
            {
                mp[it.second]=it.first->data;
            }
            if(it.first->left)
            {
                p.first=it.first->left;
                p.second=it.second-1;
                q.push(p);
            }
            if(it.first->right)
            {
                p.first=it.first->right;
                p.second=it.second+1;
                q.push(p);
            }
        }
        for(auto x:mp)
        {
            l.push_back(x.second);
        }
        return l;
        
        
    }
};