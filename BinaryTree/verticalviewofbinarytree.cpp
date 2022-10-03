{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        map<int,vector<int>>mp;
        queue<pair<Node*,int>>q;
        pair<Node*,int>p;p.first=root;p.second=0;
        q.push(p);vector<int>l;
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            mp[it.second].push_back(it.first->data);
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
            // sort(x.second.begin(),x.second.end());
            for(int i=0;i<x.second.size();i++)
            {
                l.push_back(x.second[i]);
            }
        }
        return l;
    }
};
