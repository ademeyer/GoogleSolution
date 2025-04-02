// UniqueBinarySearchTrees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        /**           left subtree * right subtree
        * --------------------------------------------
        * numTree[4] =  numTree[0] * numTree[3] +
        *               numTree[1] * numTree[2] +
        *               numTree[2] * numTree[1] +
        *               numTree[3] * numTree[0]
        */

        vector<int> n_Tree(n + 1, 1); // num of tree
        // Base cases: 
        // 0 nodes  = 1 tree
        // 1 nodes  = 1 tree
        for (int nodes = 2; nodes < n + 1; ++nodes)
        {
            auto total = 0;
            for (int root = 1; root < nodes + 1; ++root)
            {
                auto leftsubtree = root - 1;
                auto rightsubtree = nodes - root;
                total += n_Tree[leftsubtree] * n_Tree[rightsubtree];
            }
            n_Tree[nodes] = total;
        }
        return n_Tree[n];
    }
};

int main()
{
    Solution s;
    cout << "unique binary search tree: " << s.numTrees(3) << endl;
    cout << "unique binary search tree: " << s.numTrees(1) << endl;
}
