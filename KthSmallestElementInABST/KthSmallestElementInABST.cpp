// KthSmallestElementInABST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;

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
    void inorder(TreeNode* node, int& k, int& val)
    {
        if (!node) return;
        // search left
        inorder(node->left, k, val);
        --k;

        //base condition
        if (k == 0)
        {
            val = node->val;
        }

        //search right
        inorder(node->right, k, val);
    }
public:
    int kthSmallest(TreeNode* root, int k)
    {
        int result = -1;
        inorder(root, k, result);
        return result;
    }
};


int main()
{
}
