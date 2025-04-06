// CountGoodNodesInBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int goodNodes(TreeNode* root) 
    {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int maxVal) -> int
        {
            if (!node) return 0;

            auto res = node->val >= maxVal ? 1 : 0;
            maxVal = max(maxVal, node->val);
            res += dfs(node->left, maxVal);
            res += dfs(node->right, maxVal);
            
            return res;
        };
        return dfs(root, root->val);
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
