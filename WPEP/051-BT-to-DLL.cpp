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
        Intuition :
            1. The leftmost node will be the head of the DLL.
            2. The rightmost node will be the tail of the DLL.
            3. The left pointer of the node will point to the previous node in the DLL.
            4. The right pointer of the node will point to the next node in the DLL.
            5. The left pointer of the head will point to the tail.
            6. The right pointer of the tail will point to the head.
            7. The left pointer of the root will point to the tail.
            8. The right pointer of the root will point to the head.
            9. Recursively build the left and right subtree.
    */

    // helper function
    pair<TreeNode *, TreeNode *> convert(TreeNode *root)
    {
        if (!root)
            return {nullptr, nullptr};

        pair<TreeNode *, TreeNode *> left = convert(root->left);
        pair<TreeNode *, TreeNode *> right = convert(root->right);

        TreeNode *head = nullptr;
        TreeNode *tail = nullptr;

        root->left = left.second;
        if (left.second)
        {
            left.second->right = root;
            head = left.first;
        }

        root->right = right.first;

        if(right.first)
        {
            right.first->left = root;
            tail = right.second;
        }

        return {head, tail};
    }

    TreeNode *bToDLL(TreeNode *root)
    {
        return convert(root).first;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    // input : 1 3 2

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    TreeNode *head = root->bToDLL(root);

    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->right;
    }

    return 0;
}