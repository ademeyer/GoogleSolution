// SerializeAndDeserializeBinaryTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
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

class Codec
{
    void DFS_E(TreeNode* root, vector<string>& res)
    {
        if (!root)
        {
            res.push_back("N");
            res.push_back(",");
            return;
        }
        res.push_back(to_string(root->val));
        res.push_back(",");

        DFS_E(root->left, res);
        DFS_E(root->right, res);
    }

    TreeNode* DFS_D(const vector<string>& res, int& index)
    {
        if (res[index] == "N")
        {
            ++index;
            return NULL;
        }
        auto node = new TreeNode(stoi(res[index]));
        ++index;
        node->left = DFS_D(res, index);
        node->right = DFS_D(res, index);

        return node;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if (!root) return "";
        vector<string> res;

        DFS_E(root, res);

        string result = "";
        for (auto str : res)
            result += str;

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        vector<string> res;
        string tem = "";
        for (int i = 0; i < data.size(); i++)
        {
            if (data[i] == ',')
            {
                res.push_back(tem);
                tem.clear();
            }
            else
            {
                tem += data[i];
            }
        }
        res.push_back(tem);
        int index = 0;
        return DFS_D(res, index);
    }
};


int main()
{
    // Create a test tree
    auto root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); 
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    string data = "";
    Codec c;
    data = c.serialize(root);
    auto tree = c.deserialize(data);
}
