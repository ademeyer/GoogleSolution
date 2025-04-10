// FindTheKthLargestIntegerInTheArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class comp
{
public:
    bool operator()(const string& a, const string& b)
    {
        if (a.size() < b.size())
            return true;
        else if (a.size() > b.size())
            return false;
        else // same length
        {
            auto compCharValue = [](const string& a, const string& b)
            {
                auto n = a.size();
                for (int i = 0; i < n; ++i)
                {
                    if (a[i] < b[i])
                        return true;
                    else if (a[i] > b[i])
                        return false;
                }
                return false;
            };
            if (compCharValue(a, b))
                return true;
        }
        return false;
    }
};

class Solution
{
public:
    string kthLargestNumber(vector<string>& nums, int k)
    {
        priority_queue<string, vector<string>, comp> q;
        for (const auto& s : nums)
            q.push(s);

        while (--k)
            q.pop();

        return q.top();
    }
};

int main()
{
    Solution s;
    vector<string> nums = { "3","6","7","10" };
    int k = 4;
    cout << s.kthLargestNumber(nums, k) << endl;

    nums = { "2","21","12","1" };
    k = 3;
    cout << s.kthLargestNumber(nums, k) << endl;

    nums = { "0","0" };
    k = 2;
    cout << s.kthLargestNumber(nums, k) << endl;

    nums = { "683339452288515879","7846081062003424420","4805719838","4840666580043","83598933472122816064","522940572025909479","615832818268861533","65439878015","499305616484085","97704358112880133","23861207501102","919346676","60618091901581","5914766072","426842450882100996","914353682223943129","97","241413975523149135","8594929955620533","55257775478129","528","5110809","7930848872563942788","758","4","38272299275037314530","9567700","28449892665","2846386557790827231","53222591365177739","703029","3280920242869904137","87236929298425799136","3103886291279" };
    k = 3;
    cout << s.kthLargestNumber(nums, k) << endl;

}
