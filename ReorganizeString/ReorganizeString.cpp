// ReorganizeString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*

Count Frequencies: First, count the frequency of each character in the string.

Max-Heap: Use a max-heap to store characters based on their frequencies. This allows us to always pick the character with the highest remaining frequency next.

Build Result: Construct the result string by alternately placing the most frequent characters, ensuring no two adjacent characters are the same.
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& [ch, freq] : freqMap) {
            maxHeap.push({ freq, ch });
        }

        string result;
        pair<int, char> prev(-1, '#');

        while (!maxHeap.empty()) {
            auto [freq, ch] = maxHeap.top();
            maxHeap.pop();
            result += ch;

            if (prev.first > 0) {
                maxHeap.push(prev);
            }

            prev = { freq - 1, ch };
        }

        if (result.size() != s.size()) {
            return "";
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "aab";
    cout << sol.reorganizeString(s) << endl;

    s = "aaab";
    cout << sol.reorganizeString(s) << endl;

    s = "baaba";
    cout << sol.reorganizeString(s) << endl;

    s = "vvvlo";
    cout << sol.reorganizeString(s) << endl;

    return 0;
}