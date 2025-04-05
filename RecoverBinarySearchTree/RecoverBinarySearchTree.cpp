// RecoverBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

class Solution 
{
public:
    void recoverTree(TreeNode* root) 
    {
        stack<TreeNode*> st;
        TreeNode* prev = nullptr;
        TreeNode* first = nullptr;
        TreeNode* second = nullptr;
        TreeNode* cur = root;

        while (cur || !st.empty())
        {
            while (cur)
            {
                // visit left child nodes
                st.push(cur);
                cur = cur->left;
            }
            // process nodes
            cur = st.top(); st.pop();
            if (prev && prev->val > cur->val)
            {
                if (!first)
                    first = prev;
                second = cur;
            }
            prev = cur;
            // check right child node
            cur = cur->right;
        }

        // we found imbalance pair in the BST
        if (first && second)
            swap(first->val, second->val);
    }
};
int main()
{
}
