// AllNodesDistanceKInBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <vector>
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k)
    {
        if (!root) return {};
        unordered_map<TreeNode*, TreeNode*> parent_map; // child, parent
        queue<TreeNode*> q;
        q.push(root);

        // Build parent map
        while (!q.empty())
        {
            auto cur = q.front(); q.pop();
            if (cur->left)
            {
                parent_map[cur->left] = cur;
                q.push(cur->left);
            }
            if (cur->right)
            {
                parent_map[cur->right] = cur;
                q.push(cur->right);
            }
        }

        // Find nodes at distance k
        unordered_set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int distance = 0;

        while (!q.empty() && distance < k)
        {
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto cur = q.front(); q.pop();

                // check left child
                if (cur->left && !visited.count(cur->left))
                {
                    visited.insert(cur->left);
                    q.push(cur->left);
                }
                // check right child
                if (cur->right && !visited.count(cur->right))
                {
                    visited.insert(cur->right);
                    q.push(cur->right);
                }

                // check the parent
                if (parent_map.find(cur) != parent_map.end())
                {
                    auto parent = parent_map[cur];
                    if (!visited.count(parent))
                    {
                        visited.insert(parent);
                        q.push(parent);
                    }
                }
            }
            ++distance;
        }
        // retrieve nodes that are at distance k
        vector<int> res;
        while (!q.empty())
        {
            auto n = q.front(); q.pop();
            res.push_back(n->val);
        }
        return res;
    }
};


int main()
{
}
