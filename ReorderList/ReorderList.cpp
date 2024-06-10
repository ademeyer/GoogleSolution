// ReorderList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        // Find middle
        auto slow = head;
        auto fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of the list
        auto second = slow->next;
        auto prev = slow->next = NULL;
        while (second)
        {
            auto temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // merge the two halves of the list
        auto first = head;
        second = prev;
        while (second)
        {
            auto temp = first->next;
            first->next = second;
            first = temp;

            temp = second->next;
            second->next = first;
            second = temp;
        }
    }

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
};

int main()
{
    Solution s;
    vector<int> l;
    l = { 1,2,3,4 };
    auto list = s.CreateNodesFromArray(l);
    s.reorderList(list);
    s.PrintNode(list);

    l = { 1,2,3,4,5 };
    list = s.CreateNodesFromArray(l);
    s.reorderList(list);
    s.PrintNode(list);

    return 0;
}