// RemoveDuplicatesFromSortedListII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// cache value for current node
// add current node to result node
// update prevNode pointer
// if cache value is same as current node value, restore result node to prevNode pointer
// else, update prevNode pointer and result node

class Solution 
{
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
        unordered_map<int, int> mp;
        auto cur = head;
        auto resNode = new ListNode(0);
        auto rn = resNode;
        // 1, 2, 3, 3, 4, 4, 5
        while (cur)
        {
            mp[cur->val]++;
            cur = cur->next;
        }
        for (const auto& m : mp) 
        {
            if (m.second == 1)
            {
                rn->next = new ListNode(m.first);
                rn = rn->next;
            }
        }
        return resNode->next;
    }
};

ListNode* CreateNodesFromArray(const vector<int>& arr)
{
    ListNode* result = new ListNode();
    auto it = result;

    for (const auto i : arr)
    {
        ListNode* node = new ListNode(i);
        it->next = node;
        it = it->next;
    }
    return result->next;
}

void PrintNode(ListNode* head)
{
    auto it = head;
    cout << "[";
    while (it)
    {
        cout << it->val << ",";
        it = it->next;
    }
    cout << "]" << endl;
}

int main()
{
    Solution s;
    vector<int> l = { 1, 2, 3, 3, 4, 4, 5 };
    auto head = CreateNodesFromArray(l);
    auto res = s.deleteDuplicates(head);
    PrintNode(res);

    l = { 1,1,1,2,3 };
    head = CreateNodesFromArray(l);
    res = s.deleteDuplicates(head);
    PrintNode(res);

    return 0;
}