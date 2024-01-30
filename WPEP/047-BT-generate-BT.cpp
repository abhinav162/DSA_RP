#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // print tree
    void print()
    {
        TreeNode *temp = this;
        queue<TreeNode *> q;
        q.push(temp);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();
            cout << curr->val << " ";
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
        cout << "\n";
    }

    /*
    Difference between binary tree and binary search tree:
        -   In a binary tree, the left subtree of a node contains only nodes with keys less than the node’s key, and the right subtree of a node contains only nodes with keys greater than the node’s key.
        -   In a binary search tree, all the nodes in the left subtree of a node have a value less than the value of the node and all the nodes in the right subtree of a node have a value greater than the value of the node.


    Problem Statement - Given an array of preorder traversal of a BT, construct the BT.
    Approach - 
        -   We know that the first element of the preorder traversal is the root of the tree.
        -   We also know that the left subtree of the root will be all the elements less than the root and the right subtree will be all the elements greater than the root.
        -   So, we can find the first element greater than the root and then we can divide the array into two parts, one for the left subtree and one for the right subtree.
        -   We can then recursively call the function for the left and right subtree.
    */
    vector<TreeNode*> generateTrees(vector<int> &pre)
    {

    }
};

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};


    return 0 ; 
}