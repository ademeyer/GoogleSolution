// LowestCommonAncestorOfABinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        auto cur = root;
        while (cur)
        {
            if (p->val > cur->val && q->val > cur->val)
                cur = cur->right;
            else if (p->val < cur->val && q->val < cur->val)
                cur = cur->left;
            else
                return cur;
        }
        return NULL;
    }
};
int main()
{
    std::cout << "Hello World!\n";
}
