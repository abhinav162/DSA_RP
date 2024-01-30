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

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode *> q;

        q.push(root);

        bool flag = false; // setting flag to false for left to right traversal

        while (!q.empty())
        {
            vector<int> temp;
            int n = q.size();
            while (n--)
            {
                TreeNode *curr = q.front();
                q.pop();

                if (flag) // if flag is true then we have to push the element in the front of the vector
                    temp.insert(temp.begin(), curr->val);
                else // else we have to push the element in the back of the vector
                    temp.push_back(curr->val);

                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            ans.push_back(temp);
            flag = !flag;
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
    /*
    Input: root = [3,9,20,null,null,15,7]
    Output: [[3],[20,9],[15,7]]
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = nullptr;
    root->left->right = nullptr;
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ans = root->zigzagLevelOrder(root);
    
    for (auto i : ans)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }

    return 0;
}