// BinaryTreeRightSideView.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
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

    }
};

int main()
{
    std::cout << "Hello World!\n";
}
