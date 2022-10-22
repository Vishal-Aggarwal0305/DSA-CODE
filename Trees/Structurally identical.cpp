/*
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cin >> childData;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // Write your code here
    if (root1 == NULL && root2 == NULL)
        return false;
    if (root1->children.size() != root2->children.size())
        return false;
    for (int i = 0; i < root1->children.size(); i++)
    {
        bool val = areIdentical(root1->children[i], root2->children[i]);
        if (!val)
            return false;
    }
    if (root1->data != root2->data)
        return false;
    else
        return true;
}

int main()
{
    TreeNode<int> *root1 = takeInputLevelWise();
    TreeNode<int> *root2 = takeInputLevelWise();
    cout << (areIdentical(root1, root2) ? "true" : "false");
}