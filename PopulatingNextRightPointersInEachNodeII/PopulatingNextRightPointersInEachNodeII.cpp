// PopulatingNextRightPointersInEachNodeII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {
    }
};

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (!root) return root;

        queue<Node*> q;
        q.push(root);

        while (!q.empty())
        {
            int s = q.size();
            int count = 0;
            Node* nextRight = nullptr;
            while (s-- > 0)
            {
                auto n = q.front(); q.pop();
                n->next = nextRight;
                nextRight = n;
                if (n->right)
                    q.push(n->right);

                if (n->left)
                    q.push(n->left);

            }
        }
        return root;
    }
};

int main()
{

}
