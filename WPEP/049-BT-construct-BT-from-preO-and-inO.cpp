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
        Approach: 
            1. The first element in preorder is the root.
            2. Find the root in inorder.
            3. The elements to the left of the root in inorder are the left subtree.
            4. The elements to the right of the root in inorder are the right subtree.
            5. Recursively build the left and right subtree.

        Algorithm : 
            1. Create a map of inorder elements and their indices.
            2. Call the helper function with the start and end indices of preorder and inorder.
            3. The helper function will return the root of the tree.
            4. The helper function will take the start and end indices of preorder and inorder.
            5. The first element in preorder is the root.
            6. Find the root in inorder.
            7. The elements to the left of the root in inorder are the left subtree.
            8. The elements to the right of the root in inorder are the right subtree.
            9. Recursively build the left and right subtree.
    */

    // helper function
    TreeNode* buildTreeNode(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, unordered_map<int, int> &inMap)
    {
        if(preStart > preEnd) return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart], nullptr, nullptr);  // creating root node

        root->left = buildTreeNode(preorder, preStart+1, preStart+inMap[root->val]-inStart, inorder, inStart, inMap[root->val]-1, inMap);
    
        root->right = buildTreeNode(preorder, preStart+inMap[root->val]-inStart+1, preEnd, inorder, inMap[root->val]+1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;

        for(int i=0; i<inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTreeNode(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
    }
};

int main() 
{ 
    // input output for files
    freopen("../input.txt","r",stdin); 
    freopen("../output.txt","w",stdout);

    //start code here
    /*
        Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
        Output: [3,9,20,null,null,15,7]
    */

    // input
    vector<int> preO = {3,9,20,15,7}; 
    vector<int> inO = {9,3,15,20,7};


    // code
    TreeNode *root = new TreeNode();
    root->buildTree(preO, inO);

    // output
    root->print();
    return 0 ; 
}