// MaximumDepthOfBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>
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
public:
    int maxDepth(TreeNode* root)
    {
        if (!root) return 0;
        //return 1 + max(maxDepth(root->left), maxDepth(root->right));
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);
        while (!q.empty())
        {
            for (int i = 0; i < q.size(); i++)
            {
                auto node = q.front();
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            ++level;
        }
        return level;
    }
};

int main()
{
}
