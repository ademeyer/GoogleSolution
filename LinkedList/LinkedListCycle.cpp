#include <iostream>
#include <vector>
using namespace std;

 struct ListNode 
 {
    int val;
    ListNode *next;
    ListNode() {}
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    bool hasCycle(ListNode *head) 
    {
        auto slow = head;
        auto fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }

        return false;
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
    return 0;
}