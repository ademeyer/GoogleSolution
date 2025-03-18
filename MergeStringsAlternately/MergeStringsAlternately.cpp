// MergeStringsAlternately.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word;
        int i = 0;
        for (i; i < max(word1.size(), word2.size()); i++)
        {
            if (i < word1.size())
                word += word1[i];
            if (i < word2.size())
                word += word2[i];
        }
        return word;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

