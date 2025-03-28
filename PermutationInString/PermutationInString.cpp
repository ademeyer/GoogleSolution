// PermutationInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

//class Solution
//{
//public:
//    bool checkInclusion(string s1, string s2)
//    {
//        for (int i = 0; i < s2.size(); ++i)
//        {
//            unordered_map<char, int> count1;
//            for (char c : s1) {
//                count1[c]++;
//            }
//
//            int need = count1.size();
//            for (int i = 0; i < s2.length(); i++) 
//            {
//                unordered_map<char, int> count2;
//                int cur = 0;
//                for (int j = i; j < s2.length(); j++) 
//                {
//                    char c = s2[j];
//                    count2[c]++;
//
//                    if (count1[c] < count2[c]) 
//                    {
//                        break;
//                    }
//
//                    if (count1[c] == count2[c]) 
//                        cur++;
//  
//
//                    if (cur == need)
//                        return true;
//                }
//            }
//            return false;
//        }
//
//        return false;
//    }
//};

// Time complexity: O 26 + N

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Count(26, 0), s2Count(26, 0);

        for (int i = 0; i < s1.size(); ++i)
        {
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        auto matches = 0;

        for (int i = 0; i < 26; ++i)
            matches += (s1Count[i] == s2Count[i] ? 1 : 0);

        int l = 0;
        for (int r = s1.size(); r < s2.size(); ++r)
        {
            if (matches == 26) return true;

            // check the right pointer
            auto index = s2[r] - 'a';
            s2Count[index] += 1;
            if (s1Count[index] == s2Count[index])
                ++matches;
            else if ((s1Count[index] + 1) == s2Count[index])
                --matches;

            // check the left pointer
            index = s2[l] - 'a';
            s2Count[index] -= 1;
            if (s1Count[index] == s2Count[index])
                ++matches;
            else if ((s1Count[index] - 1) == s2Count[index])
                --matches;
            ++l;
        }

        return matches == 26;
    }
};

int main()
{
    Solution s;
    auto s1 = "ab";
    auto s2 = "eidbaooo";
    cout << (s.checkInclusion(s1, s2) ? "Equal" : "Not Equal") << endl;

    s1 = "ab";
    s2 = "eidboaoo";
    cout << (s.checkInclusion(s1, s2) ? "Equal" : "Not Equal") << endl;

    return 0;
}
