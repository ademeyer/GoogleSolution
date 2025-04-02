// SwapNodesInPairs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head) return head;
        auto res = new ListNode(0, head);
        auto prev = res;
        auto cur = head;

        while (cur && cur->next)
        {
            auto temp = cur->next->next;
            auto second = cur->next;

            // reverse this pair
            second->next = cur;
            cur->next = temp;
            prev->next = second;

            // update next pointer;
            prev = cur;
            cur = temp;
        }
        return res->next;
    }
};

int main()
{
}
