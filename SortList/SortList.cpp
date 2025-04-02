// SortList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
using namespace std;
// Definition for singly-linked list.
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
    auto mergeSort(ListNode* a, ListNode* b) -> ListNode*
    {
        auto tmp = new ListNode();
        ListNode* tail = tmp;
        while (a && b)
        {
            if (a->val <= b->val)
            {
                tail->next = a;
                a = a->next;
            }
            else
            {
                tail->next = b;
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b; // point to a if not null else choose b
        return tmp->next;
    };
public:
    ListNode* sortList(ListNode* head) 
    {
        if (!head || !head->next) return head;

        // Find middle
        auto slow = head;
        auto fast = head->next;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // split node at the middle
        auto mid = slow->next;
        slow->next = nullptr;

        return mergeSort(sortList(head), sortList(mid));
    }
};

void PrintNode(const ListNode* node)
{
    auto cur = node;
    while (cur)
    {
        cout << cur->val << ",";
        cur = cur->next;
    }
    cout << endl;
}

int main()
{
    auto root = new ListNode(4);
    root->next = new ListNode(2);
    root->next->next = new ListNode(1);
    root->next->next->next = new ListNode(3);

    Solution s;
    auto res = s.sortList(root);
    PrintNode(res);
}
