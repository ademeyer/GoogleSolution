// BinarySearchTreeIterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root)
    {
        // Initialize the stack by 
        // extracting root's left child node [if any]
        auto cur = root;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
    }

    int next()
    {
        auto res = st.top(); st.pop();
        // extract right child's left node [if any]
        auto cur = res->right;
        while (cur)
        {
            st.push(cur);
            cur = cur->left;
        }
        return res->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

int main()
{

}
