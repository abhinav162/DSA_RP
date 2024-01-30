/*
Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

Return the vertical order traversal of the binary tree.

Approach - 1 - nlogn
1. Do a preorder traversal and store the triplet of (val, level, hd) in a vector
2. Sort the vector based on hd, level and val
3. Push the values in a vector based on the hd

*/

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

class Solution
{
public:
    struct Triplet
    {
        int val, level, hd;
    };

    static bool cmp(struct Triplet a, struct Triplet b)
    {
        if (a.hd != b.hd)
        {
            return a.hd < b.hd;
        }

        if (a.level != b.level)
        {
            return a.level < b.level;
        }

        if (a.val < b.val)
        {
            return a.val < b.val;
        }

        return false;
    };

    void preorder(TreeNode *root, int level, int hd, vector<struct Triplet> &trips)
    {
        if (!root)
            return;
        struct Triplet t;
        t.val = root->val;
        t.level = level;
        t.hd = hd;
        trips.push_back(t);
        preorder(root->left, level + 1, hd - 1, trips);
        preorder(root->right, level + 1, hd + 1, trips);
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<struct Triplet> trips;
        preorder(root, 0, 0, trips);

        sort(trips.begin(), trips.end(), cmp);
        vector<vector<int>> ans;

        if (!root)
            return ans;

        vector<int> temp;
        temp.push_back(trips[0].val);

        for (int i = 1; i < trips.size(); i++)
        {
            if (trips[i].hd == trips[i - 1].hd)
            {
                temp.push_back(trips[i].val);
            }
            else
            {
                ans.push_back(temp);
                temp.clear();
                temp.push_back(trips[i].val);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

/*
// This approach will work only if order of node in same vertical line is not important
Approach - 2 - O(n) - Using map and queue
1. Do a level order traversal and store the triplet of (val, level, hd) in a map
2. Push the values in a vector based on the hd
3. Sort the vector based on hd
*/
class Solution2
{
public:
    vector<int> verticalOrder(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        map<int, vector<int>> m;
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});

        while (!q.empty())
        {
            TreeNode *curr = q.front().first;
            int hd = q.front().second;
            q.pop();

            m[hd].push_back(curr->val);

            if (curr->left)
                q.push({curr->left, hd - 1});
            if (curr->right)
                q.push({curr->right, hd + 1});
        }

        for (auto i : m)
        {
            for (auto j : i.second)
            {
                ans.push_back(j);
            }
        }

        return ans;
    }
};

main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
    Input: root = [3,9,20,null,null,15,7]
    Output: [[9],[3,15],[20],[7]]
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    // Solution *sol = new Solution();
    // vector<vector<int>> ans = sol->verticalTraversal(root);

    Solution2 *sol2 = new Solution2();
    vector<int> ans = sol2->verticalOrder(root);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    // for (auto i : ans)
    // {
    //     for (auto j : i)
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    return 0;
}