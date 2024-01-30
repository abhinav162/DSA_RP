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

    //// invert tree
    // mirror tree
    TreeNode *mirror(TreeNode *root)
    {
        if (root == nullptr)
            return root;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirror(root->left);
        mirror(root->right);
        return root;
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return root;
        return mirror(root);
    }

    //// is symetric
    bool checkMirror(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        if (root->left == nullptr || root->right == nullptr)
            return false;

        if (root->left == root->right)
            return true;

        return checkMirror(root->left) && checkMirror(root->right);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        return checkMirror(root->left) && checkMirror(root->right);
    }

    //// max depth
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }

    //// min depth
    int func(TreeNode *root)
    {
        if (root == nullptr)
            return INT_MAX;
        if (!root->left && !root->right)
            return 1;
        return 1 + min(func(root->left), func(root->right));
    }
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return func(root);
    }

    //// Diameter of Binary Tree
    // APPROACH - 1 : O(n^2)
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh + rh, max(diameterOfBinaryTree(root->left), diameterOfBinaryTree(root->right)));
    }

    // APPROACH - 2 : O(n)
    int height2(TreeNode *root, int &ans)
    {
        if (root == nullptr)
            return 0;

        int l = height2(root->left, ans);
        int r = height2(root->right, ans);

        ans = max(ans, l + r + 1);
        return 1 + max(l, r);
    }
    int diameterOfBinaryTree2(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int ans = INT_MIN;
        height2(root, ans);
        return ans - 1;
    }

    // APPROACH - 3 : O(n) - using pair and finding height and diameter at same time
    pair<int, int> findHeightAndDiameter(TreeNode *root)
    {
        if (root == nullptr)
            return {0, 0};

        pair<int, int> p1 = findHeightAndDiameter(root->left);
        pair<int, int> p2 = findHeightAndDiameter(root->right);
        int ht = 1 + max(p1.first, p2.first);
        int diameter = max(1 + p1.first + p2.first, max(p1.second, p2.second));

        return {ht, diameter};
    }

    int diameterOfBinaryTree3(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        pair<int, int> p = findHeightAndDiameter(root);
        return p.second - 1;
    }

    //// Balanced Binary Tree
    // APPROACH - 1 : O(n^2)
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
    int height3(TreeNode *root, bool &ans)
    {
        if (root == nullptr)
            return 0;

        int lh = height3(root->left, ans);
        int rh = height3(root->right, ans);

        if (abs(lh - rh) > 1)
            ans = false;

        return 1 + max(lh, rh);
    }

    bool isBalanced2(TreeNode *root)
    {
        if (root == nullptr)
            return true;

        bool ans = true;
        height3(root, ans);
        return ans;
    }

    //// Maximum product of splitted binary tree
    long long sumofnodes(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        return root->val + sumofnodes(root->left) + sumofnodes(root->right);
    }

    // APPROACH - 1 : O(n^2) - TLE
    int maxProduct(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        long long totalSum = sumofnodes(root);
        long long ans = INT_MIN;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left)
            {
                q.push(curr->left);
                long long leftSum = sumofnodes(curr->left);
                ans = max(ans, (leftSum * (totalSum - leftSum)));
            }
            if (curr->right)
            {
                q.push(curr->right);
                long long rightSum = sumofnodes(curr->right);
                ans = max(ans, (rightSum * (totalSum - rightSum)));
            }
        }
        return ans % 1000000007;
    }

    // APPROACH - 2 : O(n)
    long long findMaxProduct(TreeNode *root, long long &ans, long long totalSum)
    {
        if (root == nullptr)
            return 0;

        long long lp = findMaxProduct(root->left, ans, totalSum);
        long long rp = findMaxProduct(root->right, ans, totalSum);

        long long currProduct = max(lp * (totalSum - lp), rp * (totalSum - rp));
        ans = max(ans, currProduct);

        return lp + rp + root->val;
    }

    int maxProduct2(TreeNode *root)
    {
        if (root == nullptr)
            return 0;

        long long totalSum = sumofnodes(root);
        long long ans = INT_MIN;

        findMaxProduct(root, ans, totalSum);

        return ans % 1000000007;
    }

    //// Sum of left leaf
    int findSum(TreeNode *root, bool isLeft)
    {
        if (root == nullptr)
            return 0;

        if (root->left == nullptr && root->right == nullptr && isLeft)
            return root->val;

        return findSum(root->left, true) + findSum(root->right, false);
    }
    int sumOfLeftLeaves(TreeNode *root)
    {
        return findSum(root, false);
    }

    //// pseudo palindromic paths
    //  APPROACH - 1 : O(n)
    /*
        1. traverse the tree
        2. if leaf node, check if palindrome using map ( the thing is a palindrome contains atmost 1 odd frequency character)
        3. if yes, increment ans
    */
    void checkPathPalindrome(TreeNode *root, map<int, int> &m, int &ans)
    {
        if (root == nullptr)
            return;

        m[root->val]++;

        if (root->left == nullptr && root->right == nullptr)
        {
            int odd = 0;
            for (auto i : m)
            {
                if (i.second % 2 != 0)
                    odd++;
            }
            if (odd <= 1)
                ans++;
            m[root->val]--;
            return;
        }

        checkPathPalindrome(root->left, m, ans);
        checkPathPalindrome(root->right, m, ans);
        m[root->val]--;
    }

    int pseudoPalindromicPaths(TreeNode *root)
    {
        map<int, int> m;

        int ans = 0;
        checkPathPalindrome(root, m, ans);

        return ans;
    }

    //// Preorder Traversal recursive
    void preorder(TreeNode *root)
    {
        if (!root)
            return;

        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    //// Preorder traversal iterative
    vector<int> preorderIt(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<TreeNode *> st;
        st.push(root);

        while (!st.empty() || root)
        {
            TreeNode *curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            if (curr->right)
                st.push(curr->right);
            if (curr->left)
                st.push(curr->left);

            root = curr->left;
        }

        return ans;
    }

    //// Inorder Traversal Recursive
    void inorder(TreeNode *root)
    {
        if (!root)
            return;

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    //// Inorder Traversal Iterative
    vector<int> inorderIt(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<pair<TreeNode *, bool>> st;
        st.push({root, false});

        while (!st.empty())
        {
            TreeNode *curr = st.top().first;

            bool isVisited = st.top().second;
            st.pop();

            if (isVisited)
            {
                ans.push_back(curr->val);
            }
            else
            {
                if (curr->right)
                    st.push({curr->right, false});

                st.push({curr, true});

                if (curr->left)
                    st.push({curr->left, false});
            }
        }

        return ans;
    }

    //// Inorder Iterative without using flag
    vector<int> inorderIt2(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (curr)
        {
            st.push(curr);
            curr = curr->left;
        }

        while (!st.empty())
        {
            TreeNode *curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            TreeNode *r = curr->right;
            while (r)
            {
                st.push(r);
                r = r->left;
            }
        }

        return ans;
    }

    //// Postorder Traversal Recursive
    void postorder(TreeNode *root)
    {
        if (!root)
            return;

        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    //// Postorder Traversal Iterative
    vector<int> postorderIt(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;

        stack<pair<TreeNode *, bool>> st;
        st.push({root, false});

        while (!st.empty())
        {
            TreeNode *curr = st.top().first;

            bool isVisited = st.top().second;
            st.pop();

            if (isVisited)
            {
                ans.push_back(curr->val);
            }
            else
            {
                st.push({curr, true});
                if (curr->right)
                    st.push({curr->right, false});
                if (curr->left)
                    st.push({curr->left, false});
            }
        }

        return ans;
    }

    //// Level Order Traversal
    void levelOrderTraversal(TreeNode *root)
    {
        if (!root)
            return;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *curr = q.front();
            q.pop();

            cout << curr->val << " ";

            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }

    //// Level Order Traversal but with seperate each level
    vector<vector<int>> levelOrderTraversal2(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            vector<int> temp;
            int sz = q.size();
            while (sz--)
            {
                TreeNode *n = q.front();
                q.pop();
                temp.push_back(n->val);
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }

    //// level order traversal without queue
    void preOrder(TreeNode *root, int l, vector<pair<int,int>> &v, int &maxLevel) {
        if(!root) return;
        v.push_back({root->val, l});
        preOrder(root->left, l+1, v, maxLevel);
        preOrder(root->right, l+1, v, maxLevel);
    }
    vector<vector<int>> levelOrderTraversal3(TreeNode* root)
    {
        vector<pair<int,int>> v;
        int maxLevel = -1;
        preOrder(root, 0, v, maxLevel);
        vector<vector<int>> ans(maxLevel+1);
        
        if (!root)
            return ans;

        for(int i=0; i<v.size(); i++) {
            ans[v[i].second].push_back(v[i].first);
        }

        return ans;
    }

    //// Right view of binary tree
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            ans.push_back(q.back()->val);
            int sz = q.size();
            while (sz--)
            {
                TreeNode *n = q.front();
                q.pop();
                if (n->left)
                    q.push(n->left);
                if (n->right)
                    q.push(n->right);
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
    // input 1,2,2,3,4,4,3
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Original Tree : \n";
    root->print();
    root->invertTree(root);
    cout << "Inverted Tree : \n";
    root->print();

    cout << "Max Depth : " << root->maxDepth(root) << "\n";
    cout << "Min Depth : " << root->minDepth(root) << "\n";

    cout << "Is Symmetric : " << root->isSymmetric(root) << "\n";

    cout << "Preorder Traversal : ";
    root->preorder(root);

    cout << "\nPreorder Traversal Iterative : ";
    vector<int> ans = root->preorderIt(root);
    for (auto i : ans)
        cout << i << " ";

    cout << "\nInorder Traversal : ";
    root->inorder(root);

    cout << "\nInorder Traversal Iterative : ";
    ans = root->inorderIt2(root);
    for (auto i : ans)
        cout << i << " ";

    root->levelOrderTraversal(root);
    return 0;
}