// FlattenBinaryTreeToLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
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
    void flatten(TreeNode* root)
    {
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* node) -> TreeNode*
        {
            if (!node) return nullptr;

            auto leftTail = dfs(node->left);
            auto rightTail = dfs(node->right);

            if (node->left)
            {
                leftTail->right = node->right;
                node->right = node->left;
                node->left = nullptr;
            }

            return rightTail ? rightTail : (leftTail ? leftTail : node);
        };

        dfs(root);
    }
};

int main()
{
}
