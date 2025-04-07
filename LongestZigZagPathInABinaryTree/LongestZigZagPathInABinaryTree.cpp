// LongestZigZagPathInABinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
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

struct TreeInfo
{
    TreeNode* n;
    char dir;
    int n_Steps;
};

class Solution 
{
public:
    int longestZigZag(TreeNode* root) 
    {
        if (!root) return 0;
        queue<TreeInfo> q;
        if (root->left)
            q.push({ root->left, 'L', 1 });
        if (root->right)
            q.push({ root->right, 'R', 1 });

        auto bestMax = 0;
        while (!q.empty())
        {
            auto [node, frm, steps] = q.front(); // requires C++20
            q.pop();
            bestMax = max(bestMax, steps);

            if (node->left)
            {
                if(frm == 'R')
                    q.push({ node->left, 'L', steps + 1 }); // continue counting step zigzag
                if (frm == 'L')
                    q.push({ node->left, 'L', 1 });         // start a new step count
            }
            if (node->right)
            {
                if (frm == 'L')
                    q.push({ node->right, 'R', steps + 1 }); // continue counting step zigzag
                if (frm == 'R')
                    q.push({ node->right, 'R', 1 });         // start a new step count
            }
        }
        
        return bestMax;
    }
};

int main()
{

}
