// MergeTwoSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* result = new ListNode();
        auto it = result;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                it->next = list1;
                list1 = list1->next;
            }
            else
            {
                it->next = list2;
                list2 = list2->next;
            }

            it = it->next;
        }

        if (list1)
        {
            it->next = list1;
        }
        if (list2)
        {
            it->next = list2;
        }
        return result->next;
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
    vector<int> l1, l2;
    l1 = { 1,2,4 };
    l2 = { 1,3,4 };
    auto list1 = s.CreateNodesFromArray(l1);
    auto list2 = s.CreateNodesFromArray(l2);
    auto list = s.mergeTwoLists(list1, list2);
    s.PrintNode(list);


    l1 = {};
    l2 = {};
    list1 = s.CreateNodesFromArray(l1);
    list2 = s.CreateNodesFromArray(l2);
    list = s.mergeTwoLists(list1, list2);
    s.PrintNode(list);


    l1 = {};
    l2 = { 0 };
    list1 = s.CreateNodesFromArray(l1);
    list2 = s.CreateNodesFromArray(l2);
    list = s.mergeTwoLists(list1, list2);
    s.PrintNode(list);


    return 0;
}