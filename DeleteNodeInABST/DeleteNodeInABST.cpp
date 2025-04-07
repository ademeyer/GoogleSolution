// DeleteNodeInABST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (!root) return root;

        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        // we found the node to delete
        else
        {
            if (!root->left)
                return root->right;
            else if (!root->right)
                return root->left;

            // Find the min from the right subtree
            auto cur = root->right;
            while (cur->left)
                cur = cur->left;
            root->val = cur->val; // replacing node trageted for delete with the 
                                   // appro. val to keep the tree balance
            root->right = deleteNode(root->right, root->val);
        }
        return root;
    }
};

int main()
{

}
