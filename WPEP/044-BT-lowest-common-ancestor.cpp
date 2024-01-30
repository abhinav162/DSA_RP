#include <bits/stdc++.h>
using namespace std;

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
};

/*
Approach - 1 : O(n)
    Intuition:
        -   If the current (sub)tree contains both p and q, then the function result is their LCA.
        -   If only one of them is in that subtree, then the result is that one of them.
        -   If neither are in that subtree, the result is null/None/nil.

    Algorithm:
        -   Traverse the tree in postorder fashion to search if p or q is present in the current subtree.
        -   If both p and q are present in the current subtree, then return their LCA.
        -   If only one of them is present, return that one of them.
        -   If neither are present, return null/None/nil.

*/
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        if (root == p || root == q)
            return root;

        TreeNode *leftCheck = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightCheck = lowestCommonAncestor(root->right, p, q);

        if (leftCheck && rightCheck)
            return root;
        if (leftCheck)
            return leftCheck;
        if (rightCheck)
            return rightCheck;

        return NULL;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
    Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
    Output: 3
    */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution *sol = new Solution();
    TreeNode *ans = sol->lowestCommonAncestor(root, root->left, root->right);

    cout << ans->val << "\n";

    return 0;
}