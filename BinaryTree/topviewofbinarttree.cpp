struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<pair<Node*,int>>q;
        vector<int>l;map<int,int>mp;int line=0;
        pair<Node*,int>p;p.first=root;p.second=line;q.push(p);
        // return l;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            if(mp.find(it.second)==mp.end())
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
