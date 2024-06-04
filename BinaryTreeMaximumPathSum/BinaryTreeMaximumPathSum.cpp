// BinaryTreeMaximumPathSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    int DFS(TreeNode* root, int& result)
    {
        if (!root) return 0;

        int leftMax = DFS(root->left, result);
        int rightMax = DFS(root->right, result);

        leftMax = max(leftMax, 0);
        rightMax = max(rightMax, 0);
        result = max(result, (root->val + leftMax + rightMax));

        return root->val + max(leftMax, rightMax);
    }
public:
    int maxPathSum(TreeNode* root)
    {
        if (!root) return 0;
        int result = root->val;
        DFS(root, result);
        return result;
    }
};

int main()
{
}