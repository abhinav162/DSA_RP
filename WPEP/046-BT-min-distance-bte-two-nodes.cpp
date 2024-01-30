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
    Question - 
        Given a binary tree and two node values your task is to find the minimum distance between them.
    
    Approach - 1 : O(n)
    Intuition:
        -  Find the LCA of the two nodes.
        -  Find the level of the LCA node.
        -  Find the level of the two nodes and add their distance from the LCA node. 
    Algorithm:
        -   Find the LCA of the two nodes.
        -   Find the level of the LCA node.
        -   Find the level of the two nodes and add their distance from the LCA node.

    */
    TreeNode* findLCA(TreeNode* root, int a, int b)
    {
        if(!root)
            return NULL;

        if(root->val == a || root->val == b)
            return root;

        TreeNode* leftCheck = findLCA(root->left, a, b);
        TreeNode* rightCheck = findLCA(root->right, a, b);

        if(leftCheck && rightCheck)
            return root;
            
        if(leftCheck)
            return leftCheck;
        else
            return rightCheck;

        return NULL;
    }

    int findLevel(TreeNode* root, int a, int level)
    {
        if(!root) return -1;

        if(root->val == a) return level;

        int leftCheck = findLevel(root->left, a, level+1);
        if(leftCheck == -1)
            return findLevel(root->right, a, level+1);

        return leftCheck;
    }

    int findDist(TreeNode* root, int a, int b) {
        if(!root)
            return 0;

        TreeNode* lca = findLCA(root, a, b);
        int d1 = findLevel(lca, a, 0);
        int d2 = findLevel(lca, b, 0);

        return d1 + d2;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    TreeNode *root = new TreeNode(11);
    root->left = new TreeNode(22);
    root->right = new TreeNode(33);
    root->left->left = new TreeNode(44);
    root->left->right = new TreeNode(55);
    root->right->left = new TreeNode(66);
    root->right->right = new TreeNode(77);

    int a = 77, b = 22;

    cout << root->findDist(root, a, b);
    return 0;
}