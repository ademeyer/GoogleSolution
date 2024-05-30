#include <iostream>
#include <vector>
using namespace std;

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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* result = new ListNode(0, head);
        auto left = result;
        auto right = head;

        while(n > 0 && right)
        {
            right = right->next;
            --n;
        }

        while(right)
        {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return result->next;
    }

    ListNode* CreateNodesFromArray(const vector<int>& arr)
    {
        ListNode* result = new ListNode();
        auto it = result;

        for(const auto i : arr)
        {
            ListNode* node = new ListNode(i);
            it->next = node;
            it = it->next;
        }
        return result->next;
    }

    void PrintNode(ListNode* head)
    {
        auto it  = head;
        cout << "[";
        while(it)
        {
            cout << it->val << ",";
            it = it->next;
        }
        cout << "]" << endl;
    }
};

int main()
{
    Solution s;
    vector<int> l;
    l = {1,2,3,4,5};
    auto list1 = s.CreateNodesFromArray(l);
    auto list = s.removeNthFromEnd(list1, 2);
    s.PrintNode(list);

    l = {1};
    list1 = s.CreateNodesFromArray(l);
    list = s.removeNthFromEnd(list1, 1);
    s.PrintNode(list);

    l = {1, 2};
    list1 = s.CreateNodesFromArray(l);
    list = s.removeNthFromEnd(list1, 1);
    s.PrintNode(list);

    return 0;
}