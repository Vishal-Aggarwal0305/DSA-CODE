
/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution{
    public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*>st1,st2;
        vector<int>l;
        st1.push(node);
        while(!st1.empty())
        {
            auto it=st1.top();
            st1.pop();
            st2.push(it);
            if(it->left)
            {
                st1.push(it->left);
            }
            if(it->right)
            st1.push(it->right);
        }
        while(!st2.empty())
        {
            l.push_back(st2.top()->data);
            st2.pop();
        }
        return l;
    }
};