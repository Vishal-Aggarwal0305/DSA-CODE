class Solution{
    public:
    vector<int> preOrder(Node* root)
    {
        //code here
        vector<int>l;
        stack<Node*>st;
        st.push(root);
        while(!st.empty())
        {
            l.push_back(st.top()->data);
            auto it=st.top();
            st.pop();
            if(it->right)
            st.push(it->right);
            if(it->left)
            st.push(it->left);
            
        }
        return l;
        
    }
};