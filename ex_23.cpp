#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) {
            priority_queue<int, vector<int>, greater<int>> pri;

            for (auto &i: lists) {
                for (auto j = i; j != nullptr; j = j->next) {
                    pri.emplace(j->val);
                }
            }
            ListNode *head = new ListNode();
            ListNode *p = head;

            while (!pri.empty()) {
                p->next = new ListNode(pri.top());
                p = p->next;
                pri.pop();
            }
            return head->next;
        }
};

int main(void)
{


    return 0;
}
