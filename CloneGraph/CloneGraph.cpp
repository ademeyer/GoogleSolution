// CloneGraph.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// Definition for a Node.
class Node 
{
public:
    int val;
    vector<Node*> neighbors;
    Node() 
    {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val)     
    {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution 
{
    Node* dfs(Node* node, unordered_map<Node*, Node*>& hash)
    {
        if (hash.find(node) != hash.end())
        {
            return hash[node];
        }
        auto copy = new Node(node->val);
        hash[node] = copy;
        for (auto n : node->neighbors)
        {
            auto newNei = new Node(n->val);
            copy->neighbors.push_back(dfs(n, hash));
        }
        return copy;
    }
public:
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*, Node*> oldToNew;
        if(node)
            return dfs(node, oldToNew);
        return NULL;
    }
};

int main()
{
}
