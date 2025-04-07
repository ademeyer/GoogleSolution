// KthLargestSumInABinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    long long kthLargestLevelSum(TreeNode* root, int k)
    {
        using LL = long long;
        if (!root) return -1;
        queue<TreeNode*> q;
        priority_queue<LL> val;

        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            LL sum = 0;
            for (int i = 0; i < n; ++i)
            {
                auto node = q.front(); q.pop();
                sum += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            val.push(sum);
        }

        while (--k && !val.empty())
            val.pop();

        return val.empty() ? -1 : val.top();
    }
};

int main()
{

}
