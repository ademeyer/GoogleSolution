// DesignAddAndSearchWordsDataStructure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode() : children(unordered_map<char, TrieNode*>()), endOfWord(false) {}
};

class WordDictionary
{
    TrieNode* root = NULL;
public:
    WordDictionary()
    {
        root = new TrieNode();
    }

    void addWord(string word)
    {
        auto cur = root;
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
        function<bool(int, TrieNode*)> dfs = [&](int j, TrieNode* node)
        {
            for (int i = j; i < word.size(); i++)
            {
                char c = word[i];
                if (c == '.')
                {
                    for (auto child : node->children)
                    {
                        if (dfs((i + 1), child.second))
                        {
                            return true;
                        }
                    }
                    return false;
                }
                else
                {
                    if (node->children.find(c) == node->children.end())
                        return false;
                    node = node->children[c];
                }
            }
            return node->endOfWord;
        };

        auto cur = root;
        return dfs(0, cur);
    }
};

int main()
{
    WordDictionary wordDictionary;
    wordDictionary.addWord("bad");
    wordDictionary.addWord("dad");
    wordDictionary.addWord("mad");
    cout << (wordDictionary.search("pad")? "True" : "False") << endl;  // return False
    cout << (wordDictionary.search("bad") ? "True" : "False") << endl; // return True
    cout << (wordDictionary.search(".ad") ? "True" : "False") << endl; // return True
    cout << (wordDictionary.search("b..") ? "True" : "False") << endl; // return True
    cout << (wordDictionary.search("a") ? "True" : "False") << endl; // return True
}
