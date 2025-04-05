// DiameterOfBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
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
    int diameterOfBinaryTree(TreeNode* root)
    {
        int res = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int
        {
            if (!node) return 0;

            auto left = dfs(node->left); // height of left branch
            auto right = dfs(node->right); // height of right branch

            res = max(res, left + right);

            return 1 + max(left, right);
        };

        dfs(root);
        return res;
    }
};

int main()
{

}