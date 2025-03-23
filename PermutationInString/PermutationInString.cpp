// PermutationInString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        for (int i = 0; i < s2.size(); ++i)
        {
            unordered_map<char, int> count1;
            for (char c : s1) {
                count1[c]++;
            }

            int need = count1.size();
            for (int i = 0; i < s2.length(); i++) 
            {
                unordered_map<char, int> count2;
                int cur = 0;
                for (int j = i; j < s2.length(); j++) 
                {
                    char c = s2[j];
                    count2[c]++;

                    if (count1[c] < count2[c]) 
                    {
                        break;
                    }

                    if (count1[c] == count2[c]) 
                        cur++;
  

                    if (cur == need)
                        return true;
                }
            }
            return false;
        }

        return false;
    }
};

int main()
{
    unordered_map<char, int> mp1, mp2;
    cout << (mp1 == mp2 ? "Equal" : "Not Equal") << endl;

    mp1['a'] = 1;
    mp2['a'] = 2;
    cout << (mp1 == mp2 ? "Equal" : "Not Equal") << endl;

    mp1['a'] = 1;
    mp2['a'] = 1;
    cout << (mp1 == mp2 ? "Equal" : "Not Equal") << endl;

    mp1['a'] = 1;
    mp2['b'] = 1;
    cout << (mp1 == mp2 ? "Equal" : "Not Equal") << endl;

}
