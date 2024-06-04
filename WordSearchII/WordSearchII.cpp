// WordSearchII.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Time: O(m x (4 x 3^(L-1))) -> m

#include <iostream>
#include <unordered_map>
#include <functional>
#include <vector>
#include <set>

using namespace std;

struct TrieNode
{
    unordered_map<char, TrieNode*> children;
    bool endOfWord;
    TrieNode() : children(unordered_map<char, TrieNode*>()), endOfWord(false){}

    void addWord(string word)
    {
        auto cur = this;
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
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        for (auto w : words)
            root->addWord(w);

        int ROWS = board.size();
        int COLS = board[0].size();

        vector<string> result;
        set<string> res;
        set<pair<int, int>> visited;

        function<void(int, int, TrieNode*,  string)> 
            dfs = [&](int r, int c, TrieNode* node, string word)
        {
            /*
            * if we have reached the end of row and column, or
            * we have visited this path before or 
            * the char we seek is not in our node, we return.
            */
            if( r < 0 || r == ROWS ||
                c < 0 || c == COLS ||
                visited.count({r,c}) ||
                node->children.find(board[r][c]) == node->children.end())
            {
                return;
            }

            // we mark this r,c visited during the next recursion phase
            visited.insert({ r,c });
            // move to the next node
            node = node->children[board[r][c]];
            // move to the next char
            word += board[r][c];
            // if word exists, we add to result
            if (node->endOfWord)
                res.insert(word);

            // we find all other direction recursively
            dfs(r + 1, c, node, word);
            dfs(r - 1, c, node, word);
            dfs(r, c + 1, node, word);
            dfs(r, c - 1, node, word);

            // we didn't find the char in the node, umark visited
            visited.erase({ r,c });

        };

        for(int i = 0; i < ROWS; ++i)
            for(int j = 0; j < COLS; ++j)
                dfs(i, j, root, "");
        
        // process result
        for (auto word : res)
            result.push_back(word);

        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> board = { {'o','a','a','n'}, {'e','t','a','e'}, {'i','h','k','r'}, {'i','f','l','v'}, };
    vector<string> words = { "oath","pea","eat","rain" };
    auto res = s.findWords(board, words);
    cout << "[";
    for (auto str : res)
        cout << str << ",";
    cout << "]" << endl;

    board = { {'a','b'}, {'c','d'} };
    words = { "abcb" };
    res = s.findWords(board, words);
    cout << "[";
    for (auto str : res)
        cout << str << ",";
    cout << "]" << endl;

    board = { {'o','a','b','n'}, {'o','t','a','e'}, {'a','h','k','r'}, {'a','f','l','v'}, };
    words = { "oa","oaa" };
    res = s.findWords(board, words);
    cout << "[";
    for (auto str : res)
        cout << str << ",";
    cout << "]" << endl;
}
