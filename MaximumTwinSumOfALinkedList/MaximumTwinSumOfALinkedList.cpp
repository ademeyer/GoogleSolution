// MaximumTwinSumOfALinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    int pairSum(ListNode* head)
    {
        auto slow = head;
        auto fast = head;
        ListNode* prev = nullptr;

        while (fast && fast->next)
        {
            fast = fast->next->next;
            auto tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }

        auto res = 0;
        while (slow && prev)
        {
            res = max(res, prev->val + slow->val);
            prev = prev->next;
            slow = slow->next;
        }

        return res;
    }
};

int main()
{

}
