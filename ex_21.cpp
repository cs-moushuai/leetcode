#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        ListNode *p;
        if (l1->val < l2->val)
        {
            p = l1;
            p->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            p = l2;
            p->next = mergeTwoLists(l1, l2->next);
        }
        return p;
    }
};


class Solution3 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};

class Solution2
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *head = nullptr, *tail = nullptr;
        bool flag = false;
        while (l1 || l2)
        {
            if (l1 != nullptr && l2 != nullptr)
            {
                if (l1->val < l2->val)
                {
                    if (!flag)
                    {
                        head = tail = l1;
                        flag = true;

                    }
                    else
                    {
                        tail->next = l1;
                        tail = l1;
                    }
                    l1 = l1->next;
                }
                else if (l2->val <= l1->val)
                {
                    if (!flag)
                    {
                        head = tail = l2;
                        flag = true;
                    }
                    else
                    {
                        tail->next = l2;
                        tail = l2;
                    }
                    l2 = l2->next;

                }
            }
            else if (l1 != nullptr)
            {
                if (!flag)
                {
                    head = tail = l1;
                    flag = true;
                }
                else
                {
                    tail->next = l1;
                    tail = l1;
                }
                l1 = l1->next;
            }
            else if (l2 != nullptr)
            {
                if (!flag)
                {
                    head = tail = l2;
                    flag = true;
                }
                else
                {
                    tail->next = l2;
                    tail = l2;
                }
                l2 = l2->next;
            }
        }
        return head;
    }
};

int main(void)
{

    return 0;
}
