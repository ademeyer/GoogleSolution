// ValidateBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
using UL = long long;

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
    auto valid (TreeNode* node, UL left, UL right) -> bool
    {
        if (!node)
            return true;
        if (!(node->val < right && node->val > left))
            return false;
        // recursively, we find subtrees
        return ((valid(node->left, left, node->val)) && (valid(node->right, node->val, right)));
    }
public:
    bool isValidBST(TreeNode* root)
    {
        return valid(root, -LLONG_MAX, LLONG_MAX);
    }
};

int main()
{
}