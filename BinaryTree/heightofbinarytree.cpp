class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if(!node)return 0;
        
        int k=height(node->left);
        int p=height(node->right);
        int l=max(k,p);
        return 1+l;
    }
};