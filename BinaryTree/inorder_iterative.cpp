
/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        //code here
        stack<Node*>st;
        vector<int>l;
        Node*p=root;
        while(1)
        {
            if(p)
            {
               st.push(p);
               p=p->left;
            }
            else
            {
                if(st.empty())break;
                p=st.top();st.pop();
                l.push_back(p->data);
                p=p->right;
            }
            
        }
        return l;
    }
};