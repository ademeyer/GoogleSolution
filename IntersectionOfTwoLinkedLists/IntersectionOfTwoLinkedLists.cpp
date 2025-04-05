// IntersectionOfTwoLinkedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
    {
        auto curA = headA;
        auto curB = headB;
        while (curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;

    }
};

int main()
{
}
