// ConvertSortedListToBinarySearchTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <functional>

using namespace std;
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// Definition for a binary tree node.
 struct TreeNode {
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
     TreeNode* sortedListToBST(ListNode* head) 
     {
         if (!head) return nullptr;
         vector<int> listVal;
         auto cur = head;
         while (cur)
         {
             listVal.push_back(cur->val);
             cur = cur->next;
         }

         function<TreeNode*(int, int)> helper = [&](int l, int r) -> TreeNode*
         {
             if (l > r) return nullptr;
             auto mid = (l + r) / 2;
             auto root = new TreeNode(listVal[mid]);
             root->left = helper(l, mid - 1); // all element to the left of mid
             root->right = helper(mid + 1, r); // all element to the right of mid
             return root;
         };

         return helper(0, listVal.size() - 1);
     }
 };

int main()
{
}
