// DeleteTheMiddleNodeOf a Linked List.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
    ListNode* deleteMiddle(ListNode* head)
    {
        if (!head->next) return nullptr;
        ListNode* prev = nullptr;
        auto newHead = head;
        auto slow = newHead;
        auto fast = newHead;

        while (slow && fast->next)
        {
            prev = slow;
            slow = slow->next;
            if (!fast->next->next)
                break;
            fast = fast->next->next;
        }

        // sever node
        if (slow)
        {
            prev->next = slow->next;
            slow->next = nullptr;
        }

        return newHead;
    }
};

int main()
{
}
