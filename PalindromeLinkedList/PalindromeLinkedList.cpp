// PalindromeLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool isPalindrome(ListNode* head) 
    {
        auto fast = head;
        auto slow = head;

        // find middle (slow)
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse second half of the listnode
        ListNode* prev = nullptr;
        while (slow)
        {
            auto temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }

        // check for palidrome
        auto left = head;
        auto right = prev;
        while (right)
        {
            if (left->val != right->val)
                return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

int main()
{
}

