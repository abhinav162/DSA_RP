#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        cout << "\n";
    }

    // APPROACH - 1 : O(n^2)
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        int lh = height(root->left);
        int rh = height(root->right);

        if (abs(lh - rh) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    // APPROACH - 2 : O(n)
    int height2(TreeNode *root, bool &ans)
    {
        if (root == nullptr)
            return 0;

        int lh = height2(root->left, ans);
        int rh = height2(root->right, ans);

        if (abs(lh - rh) > 1)
            ans = false;

        return 1 + max(lh, rh);
    }

    bool isBalanced2(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        bool ans = true;
        height2(root, ans);
        return ans;
    }
};

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->print();
    
    return 0 ; 
}