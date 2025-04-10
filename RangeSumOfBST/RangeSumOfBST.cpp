// RangeSumOfBST.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <functional>
#include <iostream>
#include <vector>
#include <queue>
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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        int res = 0;
        function<void(TreeNode*)> dfs = [&](TreeNode* node) 
        {
            if (!node) return;
            if (node->val <= high && node->val >= low)
                res += node->val;
            dfs(node->left);
            dfs(node->right);
        };

        dfs(root);

        return res;
    }
};

int main()
{

}
