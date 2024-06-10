// MergeKSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty()) return NULL;

        while (lists.size() > 1)
        {
            vector<ListNode*> mergedList;
            for (int i = 0; i < lists.size(); i = i + 2)
            {
                ListNode* l1 = lists.at(i);
                ListNode* l2 = NULL;
                if ((i + 1) < lists.size())
                    l2 = lists.at(i + 1);

                mergedList.push_back(mergeTwoLists(l1, l2));
            }
            lists = mergedList;
        }
        return lists[0];
    }
};



int main()
{
    return 0;
}
