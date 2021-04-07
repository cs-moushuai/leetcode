#include <bits/stdc++.h>
#include <cstddef>
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
private:
public:
    ListNode* sortList(ListNode* head)
    {
        vector<int> vec;
        ListNode *p = head;
        while (p != nullptr)
        {
            vec.emplace_back(p->val);
            p = p->next;
        }
        sort(vec.begin(), vec.end());
        p = head;
        int i = 0;
        while (p != nullptr)
        {
            p->val = vec[i++];
            p = p->next;
        }
        return head;
    }
};

int main(void)
{

    return 0;
}
