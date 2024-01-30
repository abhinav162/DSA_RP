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

    void insert(TreeNode *root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        if (root->val > val)
        {
            if (!root->left)
            {
                root->left = new TreeNode(val);
                return;
            }
            insert(root->left, val);
        }
        else if (root->val < val)
        {
            if (!root->right)
            {
                root->right = new TreeNode(val);
                return;
            }
            insert(root->right, val);
        }
    }

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
        Approach - 1 :
    */
    //// make BST from sorted array
    TreeNode *makeTree(vector<int> &arr, int i, int j)
    {
        if (i > j)
            return nullptr;

        // find mid element and make it as root
        int mid = (i + j) / 2;
        TreeNode *root = new TreeNode(arr[mid]);
        root->left = makeTree(arr, i, mid - 1);
        root->right = makeTree(arr, mid + 1, j);

        return root;
    }

    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size() - 1);
    }

    //// find kth smallest element using temp data structure and returning k-1th element
    void inorder(TreeNode *root, vector<int> &arr)
    {
        if (!root)
            return;
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }

    //// find kth smallest element using count and returning kth element
    void inorder2(TreeNode *root, int &count, int &ans)
    {
        if (!root)
            return;
        inorder2(root->left, count, ans);
        count--;
        if (count == 0)
        {
            ans = root->val;
            return;
        }
        inorder2(root->right, count, ans);

        return;
    }
    int kthSmallest(TreeNode *root, int k)
    {
        int ans;
        inorder2(root, k, ans);

        return ans;
    }

    //// delete node from BST
    /*
        Approach - 1 : using inorder successor
            1 - find inorder successor
            2 - copy inorder successor value to node to be deleted
            3 - delete inorder successor


        Algorithm :
            1 - if node is leaf node
                1 - delete node
            2 - if node has one child
                1 - copy child to node
                2 - delete child
            3 - if node has two child
                1 - find inorder successor
                2 - copy inorder successor value to node to be deleted
                3 - delete inorder successor
    */

    // find inorder successor 
    TreeNode* inorderSuccessor(TreeNode* root)
    {
        TreeNode* curr = root->right;
        while(curr && curr->left)
        {
            curr = curr->left;
        }
        return curr;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;

        if (root->val > key)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }

        if(!root->left && !root->right)  // if node is leaf node
        {
            return nullptr;
        }
        else if(!root->left)   // if node has right child only
        {
            return root->right;
        }
        else if(!root->right) // if node has left child only
        {
            return root->left;
        }

        // if node has two child

        // find inorder successor
        TreeNode* inorderS = inorderSuccessor(root);
        
        // copy inorder val to node
        root->val = inorderS->val;

        // delete inorder successor
        root->right = deleteNode(root->right, inorderS->val);

        return root;
    }
};

int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    /*
        sorted array = [-10,-3,0,5,9]
        output = [0,-3,9,-10,null,5]
    */

    // vector<int> arr = {-10,-3,0,5,9};
    // TreeNode* root = new TreeNode();
    // root->sortedArrayToBST(arr);

    // root->print();

    /*
        kth smallest element
        root = [3,1,4,null,2], k = 1
    */

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    // cout << root->kthSmallest(root, 1);

    // print tree
    root->print();

    // delete node from BST
    root->deleteNode(root, 3);

    root->print();

    return 0;
}