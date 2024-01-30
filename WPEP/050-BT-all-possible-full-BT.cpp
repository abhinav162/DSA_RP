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
        Approach - 1 : TC - O(n^2)
            1. If n is 1, return a tree with one node.
            2. If n is even, then it is not possible to create a full binary tree.
            3. If n is odd, then the root node will be 0.
            4. The left subtree will have i nodes and the right subtree will have n-i-1 nodes.(the idea behind this is that the root node is already counted in the n nodes and we need to subtract 1 from it to get the number of nodes in the right subtree)
            5. Recursively build the left and right subtree.
    */

    vector<TreeNode *> allPossibleFBT(int n)
    {
        vector<TreeNode *> ans;
        if (n == 1)
        {
            ans.push_back(new TreeNode(0));
            return ans;
        }

        if (n % 2 == 0)
            return ans;

        for (int i = 1; i < n; i++)
        {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i - 1);

            for (auto l : left)
            {
                for (auto r : right)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }

    /*
        Approach - 2 : using map for memoization
            1. If n is 1, return a tree with one node.
            2. If n is even, then it is not possible to create a full binary tree.
            3. If n is odd, then the root node will be 0.
            4. The left subtree will have i nodes and the right subtree will have n-i-1 nodes.(the idea behind this is that the root node is already counted in the n nodes and we need to subtract 1 from it to get the number of nodes in the right subtree)
            5. Recursively build the left and right subtree.
    */

    vector<TreeNode *> allPossibleFBT2(int n)
    {
        vector<TreeNode *> ans;

        if (n == 1)
        {
            ans.push_back(new TreeNode(0));
            return ans;
        }

        if (n % 2 == 0)
            return ans;

        unordered_map<int, vector<TreeNode *>> memo;

        for (int i = 1; i < n; i++)
        {
            vector<TreeNode *> left;
            vector<TreeNode *> right;

            if (memo.find(i) != memo.end())
            {
                left = memo[i];
            }
            else
            {
                left = allPossibleFBT(i);
                memo[i] = left;
            }

            if (memo.find(n - i - 1) != memo.end())
            {
                right = memo[n - 1 - i];
            }
            else
            {
                right = allPossibleFBT(n - i - 1);
                memo[n - i - 1] = right;
            }

            for (int j = 0; j < left.size(); j++)
            {
                for (int k = 0; k < right.size(); k++)
                {
                    TreeNode *root = new TreeNode(0);
                    root->left = left[j];
                    root->right = right[k];
                    ans.push_back(root);
                }
            }
        }

        return ans;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    int n = 7;

    TreeNode *root = new TreeNode();
    vector<TreeNode *> ans = root->allPossibleFBT2(n);

    for (auto i : ans)
    {
        i->print();
    }

    return 0;
}