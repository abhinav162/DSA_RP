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

    void findSums(TreeNode *root, int &ans)
    {
        if (!root)
            return;

        if (root->left != nullptr)
        {
            if (!root->left->left && !root->left->right)
                ans += root->left->val;
        }

        if (root->left)
            findSums(root->left, ans);
        if (root->right)
            findSums(root->right, ans);
    }

    int sumOfLeftLeaves(TreeNode *root)
    {
        if (!root)
            return 0;

        int ans = 0;
        findSums(root, ans);
        return ans;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
    Input: root = [3,9,20,null,null,15,7]
    Output: 24
    */
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << root->sumOfLeftLeaves(root) << "\n";
    return 0;
}