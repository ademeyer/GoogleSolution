// LargestRectanglenInHistogram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

/*
Time: O(n)
Space: O(n)
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
        stack<pair<int, int>> st; // index, height
        int result = 0;

        for (int i = 0; i < heights.size(); ++i)
        {
            int start = i;

            while (!st.empty() && st.top().second > heights[i])
            {
                int idx = st.top().first;
                int width = i - idx;
                int height = st.top().second;
                st.pop();

                result = max((height * width), result);
                start = idx;                    
            }
            st.push({ start, heights[i] });
        }

        while (!st.empty())
        {
            int width = heights.size() - st.top().first;
            int height = st.top().second;
            st.pop();
            result = max((height * width), result);
        }

        return result;
    }
};

int main()
{
}
