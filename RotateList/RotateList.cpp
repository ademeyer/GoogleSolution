// RotateList.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (!head || k == 0) return head;
        auto cur = head;
        vector<ListNode*> nodes;
        int n = 0;
        while (cur)
        {
            nodes.push_back(cur);
            cur = cur->next;
            ++n;
        }
        if (n == 1) return head;
        // mark node end
        auto& endNode = nodes[n - (k % n) - 1];
        endNode->next = nullptr;

        // link new head
        if (n - (k % n) != n)
        {
            auto& newHead = nodes[n - 1];
            newHead->next = nodes[0];
        }
        return nodes[(n - (k % n)) % n]; //(n - (k % n)) % n
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
    vector<int> l = { 1,2,3,4,5 };
    auto head = CreateNodesFromArray(l);
    auto res = s.rotateRight(head, 2);
    PrintNode(res);

    l = { 0,1,2 };
    head = CreateNodesFromArray(l);
    res = s.rotateRight(head, 4);
    PrintNode(res);

    l = { 1,2 };
    head = CreateNodesFromArray(l);
    res = s.rotateRight(head, 2);
    PrintNode(res);
}
