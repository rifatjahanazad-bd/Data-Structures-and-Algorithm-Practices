#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *Tree_Input()
{
    int val;
    cin >> val;
    if (val == -1)
        return NULL;
    TreeNode *root = new TreeNode(val);
    // push to queue that node
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *parent = q.front();
        q.pop();
        int x, y;
        cin >> x >> y;
        TreeNode *left, *right;
        if (x != -1)
            left = new TreeNode(x);
        else
            left = NULL;
        if (y != -1)
            right = new TreeNode(y);
        else
            right = NULL;

        parent->left = left;
        parent->right = right;
        if (left)
            q.push(left);
        if (right)
            q.push(right);
    }
    return root;
}

class Solution
{
public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        queue<TreeNode *> q;
        TreeNode *parent = root;
        q.push(parent);
        while (!q.empty())
        {
            TreeNode *Front = q.front();
            q.pop();
            if (Front->left)
            {
                sum += Front->left->val;
            }
            if (Front->right)
            {
                q.push(Front->right);
            }
        }
        return sum;
    }
    // 1 2 3 4 5 -1 8 -1 -1 6 7 9
    //  left -- right -- root
    //  using 2 stack
    vector<int> postorderTraversal_2Stack(TreeNode *root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;
        stack<TreeNode *> st, st2;
        TreeNode *parent = root;
        st.push(parent);
        while (!st.empty())
        {
            TreeNode *front = st.top();
            st.pop();
            st2.push(front);
            if (front->left)
                st.push(front->left);
            if (front->right)
                st.push(front->right);
        }
        while (!st2.empty())
        {
            v.push_back(st2.top()->val);
            st2.pop();
        }
        return v;
    }
    vector<int> postorderTraversal_1_Stack(TreeNode *root)
    {
        vector<int> v;
        if (root == nullptr)
            return v;
        stack<TreeNode *> st;
        TreeNode *parent = root;
        TreeNode *lastvisited = NULL;
        // st.push(parent);
        while (!st.empty() || parent)
        {
            // parent = parent->left;
            if (parent)
            {
                st.push(parent);
                parent = parent->left;
            }
            else
            {
                TreeNode *peekNode = st.top();
                if (peekNode->right && lastvisited != peekNode->right)
                {
                    parent = peekNode->right;
                }
                else
                {
                    v.push_back(peekNode->val);
                    lastvisited = peekNode;
                    st.pop();
                }
            }
        }
        return v;
    }
    vector<int> PreorderTraversal_1_Stack(TreeNode *root)
    {
        vector<int> v;
        TreeNode *parent = root;
        if (!parent)
            return v;
        stack<TreeNode *> st;
        st.push(parent);
        while (!st.empty())
        {
            TreeNode *front = st.top();
            st.pop();
            v.push_back(front->val);
            if (front->right)
                st.push(front->right);
            if (front->left)
                st.push(front->left);
        }
        return v;
    }
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> v;
        TreeNode *Current = root;
        if (!Current)
            return v;
        stack<TreeNode *> st;
        // st.push(root);
        while (!st.empty() || Current)
        {
            while (Current)
            {
                st.push(Current);
                Current = Current->left;
            }
            TreeNode *peek = st.top();
            if (peek->right)
            {
                v.push_back(peek->val);
                st.pop();
                Current = peek->right;
            }
            else
            {
                v.push_back(peek->val);
                st.pop();
            }
        }
        return v;
    }
    /// LEFT VIEW OF BINARY TREE
    vector<int> leftViewBinaryTree(TreeNode *root)
    {
        vector<int> v;
        if (!root)
            return v;
        bool freearr[105] = {false};
        queue<pair<TreeNode *, int>> q;
        int level = 1;
        q.push({root, level});
        while (!q.empty())
        {
            TreeNode *current = q.front().first;
            level = q.front().second;
            q.pop();
            if (!freearr[level])
            {
                v.push_back(current->val);
                freearr[level] = true;
            }
            level++;
            if (current->left)
                q.push({current->left, level});
            if (current->right)
                q.push({current->right, level});
        }
        return v;
    }
    // reverse a binary tree
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
        {
            return nullptr;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        swap(left, right);
        return root;
    }
    ////
    vector<int> CollectLeafNodes(TreeNode *root)
    {
        vector<int> v;
        TreeNode *parent = root;
        if (!parent)
            return v;
        stack<TreeNode *> st;
        st.push(parent);
        while (!st.empty())
        {
            TreeNode *front = st.top();
            st.pop();
            if (front->left && front->right)
            {
                v.push_back(front->val);
            }
            if (front->right)
                st.push(front->right);
            if (front->left)
                st.push(front->left);
        }
        return v;
    }
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return max(l, r) + 1;
    }
    // input for bst
    void inputBST(TreeNode *&root, int val)
    {
        if (!root)
        {
            root = new TreeNode(val);
            return;
        }
        if (val > root->val)
            inputBST(root->right, val);
        else
            inputBST(root->left, val);
    }
    ///
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return NULL;
        if (root->val == val) return root;
        if (root->val > val) return searchBST(root->left, val);
        else return searchBST(root->right, val);
    }
    //array to bst
    TreeNode* arraytoBST(vector <int> nums, int start_size, int end_size)
    {
        if (start_size > end_size) return NULL;
        int mid = (start_size + end_size) / 2;
        TreeNode* root = new TreeNode (nums[mid]);

        root->left = arraytoBST (nums, start_size, mid-1);
        root->right = arraytoBST (nums, mid+1, end_size);
        return root;
    }
    // array to heap
    void insert_heap (int val)
    {
        
    }

};
int main()
{
    Solution one;
    vector <int> x = {-10,-3,0,5,9};
    sort(x.begin(),)
    TreeNode *root = one.arraytoBST(x,0,x.size()-1);
    vector <int> y = one.inorderTraversal(root);
    for (int i : y)
    {
        cout << i << " ";
    }
    
}