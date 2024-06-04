// ReverseLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* current = head;

        while (current)
        {
            auto temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }

        return prev;
    }

    ListNode* reverseList_R(ListNode* head)
    {
        if (!head) return NULL;

        auto newHead = head;
        if (head->next != NULL)
        {
            newHead = reverseList_R(head->next);
            head->next->next = head;
        }
        head->next = NULL;

        return newHead;
    }
};

int main()
{

}

