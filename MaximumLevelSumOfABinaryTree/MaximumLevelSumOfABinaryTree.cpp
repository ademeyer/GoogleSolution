// MaximumLevelSumOfABinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    int maxLevelSum(TreeNode* root)
    {
        if (!root) return 0;
        int maxSum = INT_MIN;
        int maxLevel = 0;
        int curLevel = 0;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            ++curLevel;
            int levelSum = 0;
            int n = q.size();

            for (int i = 0; i < n; ++i)
            {
                auto node = q.front(); q.pop();
                levelSum += node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (levelSum > maxSum)
            {
                maxSum = levelSum;
                maxLevel = curLevel; // track the level with hight maxSum
            }
        }
        return maxLevel;
    }
};

int main()
{
    auto root = new TreeNode(1);
    root->right = new TreeNode(0);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(-8);

    Solution s;

    cout << "max level sum = " << s.maxLevelSum(root) << endl;
}
