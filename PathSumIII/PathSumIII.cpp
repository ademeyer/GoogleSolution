// PathSumIII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) 
    {
        using LL = long long;
        int total = 0;
        unordered_map<long, int> cache; // seen_sum, freq
        cache[targetSum] = 1;

        function<void(TreeNode*, LL)> dfs = [&](TreeNode* node, LL root_sum) 
        {
            if (!node) return;
            root_sum += node->val;
            total += cache[root_sum];
            cache[root_sum + targetSum]++;

            dfs(node->left, root_sum);
            dfs(node->right, root_sum);
            cache[root_sum + targetSum]--;
        };

        dfs(root, 0);
        return total;
    }
};

int main()
{

}