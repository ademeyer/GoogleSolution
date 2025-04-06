// OddEvenLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
public:
    ListNode* oddEvenList(ListNode* head)
    {
        if (!head || !head->next) return head;

        auto oddPtr = head;
        auto evenPtr = head->next; // 1, 2
        auto evenHead = evenPtr;

        while (evenPtr && evenPtr->next)
        { 
            oddPtr->next = evenPtr->next;
            oddPtr = oddPtr->next;
            evenPtr->next = oddPtr->next;
            evenPtr = evenPtr->next;
        }

        oddPtr->next = evenHead;

        return head;
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

void PrintNode(const ListNode* head)
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
    auto root = CreateNodesFromArray(vector<int>{1,2,3,4,5});
    auto res = s.oddEvenList(root);
    PrintNode(res);

    root = CreateNodesFromArray(vector<int>{2, 1, 3, 5, 6, 4, 7});
    res = s.oddEvenList(root);
    PrintNode(res);

    return 0;
}