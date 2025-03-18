// ReverseLinkedListII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution
{
public:
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        if (!head || left >= right) return head;
        ListNode* reverse = nullptr;
        ListNode* leftNode = new ListNode(0);
        ListNode* rightNode = new ListNode(0);

        auto cur = head;
        auto ln = leftNode;
        auto rn = rightNode;
        int i = 1;

        while (cur)
        {
            // 1, 2, 3, 4, 5
            if (i < left)
            {
                ln->next = new ListNode(cur->val);
                ln = ln->next;
                cur = cur->next;
            }
            else if (i > right)
            {
                rn->next = new ListNode(cur->val);
                rn = rn->next;
                cur = cur->next;
            }
            else
            {
                auto temp = cur->next;
                cur->next = reverse;
                reverse = cur;
                cur = temp;
            }

            ++i;
        }
        ListNode* result = new ListNode(0);
        auto r = result;
        if (leftNode->next)
        {
            r->next = leftNode->next;
            r = r->next;
        }

        if (reverse)
        {
            while (r->next)
                r = r->next;

            r->next = reverse;
            r = reverse;
        }

        if (rightNode->next)
        {
            while (r->next)
                r = r->next;

            r->next = rightNode->next;
        }

        return result->next;
    }
};

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

int main()
{
    Solution s;
    ListNode* l = CreateNodesFromArray(vector<int>{ 1, 2, 3, 4, 5 });
    int left = 2, right = 4;
    auto res = s.reverseBetween(l, left, right);
    PrintNode(res);

    l = CreateNodesFromArray(vector<int>{ 5 });
    left = 1, right = 1;
    res = s.reverseBetween(l, left, right);
    PrintNode(res);

    l = CreateNodesFromArray(vector<int>{ 3, 5 });
    left = 1, right = 2;
    res = s.reverseBetween(l, left, right);
    PrintNode(res);

    l = CreateNodesFromArray(vector<int>{ 1, 2, 3, 4, 5 });
    left = 1, right = 2;
    res = s.reverseBetween(l, left, right);
    PrintNode(res);

    return 0;
}
