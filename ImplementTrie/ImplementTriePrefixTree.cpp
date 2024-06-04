// ImplementTrie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode() : children(unordered_map<char, TrieNode*>()), endOfWord(false) {}
};

class Trie
{
    TrieNode* root;
public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        auto cur = this->root;
        for (auto c : word)
        {
            if (cur->children.find(c) == cur->children.end())
            {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }

    bool search(string word)
    {
        auto cur = this->root;
        for (auto c : word)
        {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        
        return cur->endOfWord;
    }

    bool startsWith(string prefix)
    {
        auto cur = this->root;
        for (auto c : prefix)
        {
            if (cur->children.find(c) == cur->children.end())
                return false;
            cur = cur->children[c];
        }
        return true;
    }
};

int main()
{
}
