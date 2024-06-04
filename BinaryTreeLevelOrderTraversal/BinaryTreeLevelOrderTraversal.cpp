// BinaryTreeLevelOrderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> result;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> res;
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                auto tree = q.front(); q.pop();
                if (tree)
                {
                    res.push_back(tree->val);
                    q.push(tree->left);
                    q.push(tree->right);
                }
            }  
            if(!res.empty())
                result.push_back(res);
        }
        return result;
    }
};





int main()
{
    std::cout << "Hello World!\n";
}