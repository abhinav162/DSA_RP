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

    struct triplet
    {
        bool isBst;
        long Min;
        long Max;
    };

    triplet isBSThelper(TreeNode *root)
    {
        if (!root)
        {
            triplet ans;
            ans.isBst = true;
            ans.Min = LONG_MAX;
            ans.Max = LONG_MIN;

            return ans;
        }

        triplet left = isBSThelper(root->left);
        triplet right = isBSThelper(root->right);

        triplet ans;
        ans.isBst = left.isBst && right.isBst && root->val > left.Max && root->val < right.Min;
        ans.Min = min((long)root->val, min(left.Min, right.Min));
        ans.Max = max((long)root->val, max(left.Max, right.Max));

        return ans;
    }

    bool isValidBST(TreeNode *root)
    {
        return isBSThelper(root).isBst;
    }

    int size(TreeNode *root)
    {
        if (!root)
            return 0;

        return 1 + size(root->left) + size(root->right);
    }

    //// Largest BST in a Binary Tree using isValidBST function and size function
    /*
        Approach :
        1. we will use post order traversal to solve this problem
        2. if the left subtree is BST and right subtree is BST and root is also BST then we will return the size of the tree
        3. if the left subtree is BST and right subtree is BST and root is not BST then we will return the size of the largest BST from left and right subtree
    */
    int largestBst(TreeNode *root)
    {
        if (!root)
            return 0;

        if (isValidBST(root))
            return size(root);

        return max(largestBst(root->left), largestBst(root->right));
    }


    //// Largest BST using Quad and storing the largest in that Quad
    struct Quad {
        bool isBst;
        long Min,Max;
        int largestBst;
    };
    
    Quad largestBSTHelper(TreeNode* root)
    {
        if(!root)
        {
            Quad ans;
            ans.isBst = true;
            ans.Min = LONG_MAX;
            ans.Max = LONG_MIN;
            ans.largestBst = 0;
            return ans;
        }

        Quad left = largestBSTHelper(root->left);
        Quad right = largestBSTHelper(root->right);

        Quad ans;
        ans.isBst = left.isBst && right.isBst && root->val > left.Max && root->val < right.Min;
        ans.Min = min((long) root->val, min(left.Min, right.Min));
        ans.Max = max((long) root->val, max(left.Max, right.Max));

        if(ans.isBst)
        {
            ans.largestBst = 1 + left.largestBst + right.largestBst;
        }
        else
        {
            ans.largestBst = max(left.largestBst, right.largestBst);
        }

        return ans;
    }

    int largestBst2(TreeNode *root)
    {
        return largestBSTHelper(root).largestBst;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
        Input: 6 6 3 N 2 9 3 N 8 8 2
        Output: 2
    */

    TreeNode *root = new TreeNode(6);
    root->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(3);
    root->right->right->right = new TreeNode(8);
    root->right->right->right->left = new TreeNode(8);
    root->right->right->right->right = new TreeNode(2);

    root->print();
    cout << root->largestBst(root);

    return 0;
}