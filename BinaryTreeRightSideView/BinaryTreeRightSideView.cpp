// BinaryTreeRightSideView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


 // Definition for a binary tree node.
 struct TreeNode 
 {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution 
{
public:
    vector<int> rightSideView(TreeNode* root) 
    {
        if (!root) return {};
        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode* rightNode = nullptr;
            int qLen = q.size();
            for (int i = 0; i < qLen; ++i)
            {
                auto n = q.front(); q.pop();
                if (n)
                {
                    rightNode = n;
                    q.push(n->left);
                    q.push(n->right);
                }
            }
            if(rightNode)
                res.push_back(rightNode->val);
        }
        return res;
    }
};

int main()
{

}
