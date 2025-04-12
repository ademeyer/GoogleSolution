// VerticalOrderTraversalOfABinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
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
    struct pack
    {
        TreeNode* n;
        int col, row;
    };
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if (!root) return {};

        // <col, map<row, multiset<values>>>
        map<int, map<int, multiset<int>>> nodesMap;

        // Queue for BFS transversal: <TreeNode, colomn, row>
        queue<pack> q;
        q.push({root, 0, 0});

        while (!q.empty())
        {
            auto [node, col, row] = q.front(); // requires C++20
            q.pop();

            nodesMap[col][row].insert(node->val); // insert col, row, value
            // check children nodes
            if (node->left) // left child
                q.push({ node->left, col - 1, row + 1 });
            if (node->right) // right child
                q.push({ node->right, col + 1, row + 1 });
        }

        vector<vector<int>> result;

        for (const auto& [col, rows] : nodesMap)
        {
            vector<int> column;
            for (const auto& [row, values] : rows)
                column.insert(column.end(), values.begin(), values.end());
            result.push_back(column);
        }
        return result;
    }
};
int main()
{

}
