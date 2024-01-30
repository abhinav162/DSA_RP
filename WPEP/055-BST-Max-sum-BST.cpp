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

    struct Quad {
        bool isBst;
        long Min,Max;
        int maxSum;
        int sum;
    };
    
    Quad maxSumBSThelper(TreeNode* root)
    {
        if(!root)
        {
            Quad ans;
            ans.isBst = true;
            ans.Min = LONG_MAX;
            ans.Max = LONG_MIN;
            ans.maxSum = 0;
            ans.sum = 0;
            return ans;
        }

        Quad left = maxSumBSThelper(root->left);
        Quad right = maxSumBSThelper(root->right);

        Quad ans;
        ans.isBst = left.isBst && right.isBst && root->val > left.Max && root->val < right.Min;
        ans.Min = min((long) root->val, min(left.Min, right.Min));
        ans.Max = max((long) root->val, max(left.Max, right.Max));
        
        if(ans.isBst)
        {
            ans.sum = root->val + left.sum + right.sum;
            ans.maxSum = max(ans.sum, max(left.maxSum, right.maxSum));
        }
        else
        {
            ans.maxSum = max(left.maxSum, right.maxSum);
        }
        return ans;
    }

    int maxSumBST(TreeNode *root)
    {
        if(maxSumBSThelper(root).maxSum > 0)
            return maxSumBSThelper(root).maxSum;
        else
            return 0;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
        Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
        Output: 20
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(2);

    root->right->left->left = new TreeNode(4);
    root->right->left->right = new TreeNode(6);

    root->print();
    root->maxSumBST(root);

    return 0;
}