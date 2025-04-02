// FindDuplicateSubtrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <functional>
#include <unordered_map>
#include <vector>
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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string, vector<TreeNode*>> subtree;
        vector<TreeNode*> result;

        function<string(TreeNode*)> dfs = [&](TreeNode* node) -> string 
        {
            if (!node) return "null";
            auto s = to_string(node->val) + "," 
                + "," + dfs(node->left) + "," 
                + dfs(node->right);

            if (subtree[s].size() == 1)
                result.push_back(node);
            subtree[s].push_back(node);
            return s;
        };

        dfs(root);
        return result;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
