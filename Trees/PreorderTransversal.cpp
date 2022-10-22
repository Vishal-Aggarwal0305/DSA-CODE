// Pre order Transversal Printing

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
};

TreeNode<int>* takeInputLevelwise() {
    int rootData;
    cout << "Enter Root Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    
    queue<TreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++){
            int childData;
            cout << "Enter  " << i <<"th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void preorder(TreeNode<int>* root){
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}

int main() {
    TreeNode<int>* root = takeInputLevelwise();
    preorder(root);
}

// INPUT

// Instead of giving the input level wise, separately write the input in a single line

// 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0

// OUTPUT

// 1 2 5 6 3 7 8 9 4