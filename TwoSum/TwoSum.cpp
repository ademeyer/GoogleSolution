
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> tracker;
        for (int i = 0; i < nums.size(); i++)
        {
            int complement = target - nums[i];
            if (tracker.find(complement) != tracker.end())
            {
                return { tracker[complement], i};
            }
            tracker[nums[i]] = i;
        }
        return {-1, -1};
    }
    /*
    Time = O(n)
    Space = O(n)
    */
};

int main()
{
    Solution s;
    vector<int> nums_1 = { 2,7,11,15 };
    int target_1 = 9;
    auto p = s.twoSum(nums_1, target_1);
    cout << "[" << p[0] << "," << p[1] << "]" << endl;

    vector<int> nums_2 = { 3,2,4 };
    int target_2 = 6;
    p = s.twoSum(nums_2, target_2);
    cout << "[" << p[0] << "," << p[1] << "]" << endl;

    vector<int> nums_3 = { 3,3 };
    int target_3 = 6;
    p = s.twoSum(nums_3, target_3);
    cout << "[" << p[0] << "," << p[1] << "]" << endl;
}

