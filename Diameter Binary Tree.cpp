/*Time Complexity of this code is O(n)*/

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    
    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    
    ~BinaryTreeNode() { /*Destructor*/
        delete left;
        delete right; 
    }
};

BinaryTreeNode<int>* takeInputLevelWise() {
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter Left Child of" << front->data <<endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        
        cout << "Enter Right Child of" << front->data <<endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(BinaryTreeNode<int>* root){
    if (root == NULL) {
        return;
    }
    cout << root->data << ":";
    if(root->left != NULL){
        cout << "L" << root->left->data;
    }
    
    if(root->right != NULL){
        cout << "R" << root->right->data;
    }
    cout<<endl;
    printTree(root->left);
    printTree(root->right);
}

pair<int, int> heightDiameter(BinaryTreeNode<int>*root) {   // pair is an inbuilt STL in C++
    if (root == NULL) {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;
    
    int height = 1 + max(lh, rh);
    int diameter = max (lh+rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

int main() {
    BinaryTreeNode<int>* root = takeInputLevelWise();
    printTree(root);
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << endl;
    cout << "Diameter: " << p.second << endl;
    delete root;
}

/*Input*/

// Enter root data
// 1 2 3 4 5 -1 -1 6 -1 -1 7 8 -1 -1 9 -1 -1 -1 -1

/*Output*/

// Enter Left Child of1
// Enter Right Child of1
// Enter Left Child of2
// Enter Right Child of2
// Enter Left Child of3
// Enter Right Child of3
// Enter Left Child of4
// Enter Right Child of4
// Enter Left Child of5
// Enter Right Child of5
// Enter Left Child of6
// Enter Right Child of6
// Enter Left Child of7
// Enter Right Child of7
// Enter Left Child of8
// Enter Right Child of8
// Enter Left Child of9
// Enter Right Child of9
// 1:L2R3
// 2:L4R5
// 4:L6
// 6:L8
// 8:
// 5:R7
// 7:R9
// 9:
// 3:
// Height: 5
// Diameter: 6