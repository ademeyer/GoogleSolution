// LinkedListCycleII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode* detectCycle(ListNode* head)
    {
        if (!head || !head->next) return nullptr;

        auto intersection = [](ListNode* node) -> ListNode*
        {
            auto slow = node;
            auto fast = node;
            while (fast && fast->next)
            {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast)
                    return slow;
            }
            return nullptr;
        };

        auto intersect = intersection(head);
        if (!intersect) return nullptr;

        auto start = head;
        while (intersect != start)
        {
            start = start->next;
            intersect = intersect->next;
        }
        return start;
    }
};

int main()
{

}
