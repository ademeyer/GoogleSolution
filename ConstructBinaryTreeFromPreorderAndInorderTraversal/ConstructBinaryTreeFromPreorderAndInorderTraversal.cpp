// ConstructBinaryTreeFromPreorderAndInorderTraversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
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
    void PrintTreeNodeLevelOrder(TreeNode* root)
    {
        if (!root) return;
        PrintTreeNodeLevelOrder(root->left);
        cout << root->val << ", ";
        PrintTreeNodeLevelOrder(root->right);
    }
    TreeNode* BuildTreeFromArray(const vector<int>& array)
    {
        TreeNode* root = NULL;
        vector<TreeNode*> ref_node;

        for (const auto a : array)
        {
            TreeNode* temp = new TreeNode(a);
            ref_node.push_back(temp);
            //delete temp;
        }

        for (int i = 0; i < array.size(); i++)
        {
            if (array[i] == -1) //(array[i] != -1 && root == NULL)
            {
                root = ref_node[i];
            }
            else //if(root)
            {
                // check if the left child is not set
                if (ref_node[array[i]]->left == NULL)
                    ref_node[array[i]]->left = ref_node[i];
                else // after adding left child, add right child
                    ref_node[array[i]]->right = ref_node[i];
            }
            /*else
            {
                cout << "unknown error" << endl;
                return NULL;
            }*/
        }
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j)
    {
        if (i > j)
            return NULL;

        TreeNode* root = new TreeNode(preorder[index]);
        int split = 0;
        for (int i = 0; i < inorder.size(); i++)
        {
            if (preorder[index] == inorder[i])
            {
                split = i;
                break;
            }
        }
        ++index;
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);

        return root;
    }
};

int main()
{
    //Solution s;
    //vector<int> arr = { 3,9,20,-1,-1,15,7 };
    //auto tree = s.BuildTreeFromArray(arr);
    //s.PrintTreeNodeLevelOrder(tree);
}

