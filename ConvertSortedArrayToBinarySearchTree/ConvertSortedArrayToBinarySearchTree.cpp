// ConvertSortedArrayToBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <functional>
#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        function<TreeNode* (int, int)> helper = [&](int l, int r) -> TreeNode* 
        {
            if (l > r)
                return nullptr;
            auto m = (l + r) / 2;
            auto root = new TreeNode(nums[m]);
            root->left = helper(l, m - 1);
            root->right = helper(m + 1, r);
            return root;
        };
        return helper(0, nums.size() - 1);
    }
};

int main()
{

}
