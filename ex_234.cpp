#include <algorithm>
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
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = nullptr, *pre = head;
        while (pre)
        {
            ListNode *t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        if (head == nullptr)
            return true;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next && fast->next->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *middle = slow->next;
        middle = reverseList(middle);
        while (middle)
        {
            if (head->val != middle->val)
                return false;
            head = head->next;
            middle = middle->next;
        }
        return true;
    }
};


class Solution2
{
private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *cur = nullptr, *pre = head;
        while (pre)
        {
            ListNode *t = pre->next;
            pre->next = cur;
            cur = pre;
            pre = t;
        }
        return cur;
    }
public:
    bool isPalindrome(ListNode* head)
    {
        ListNode *tail = head;
        int counts = 0;
        while (tail)
        {
            ++counts;
            tail = tail->next;
        }
        int iter = counts % 2 == 1 ? counts / 2 + 1 : counts / 2;
        ListNode *middle = head;
        while (iter != 0)
        {
            middle = middle->next;
            --iter;
        }
        middle = reverseList(middle);
        while (middle)
        {
            if (head->val != middle->val)
                return false;
            head = head->next;
            middle = middle->next;
        }
        return true;
    }
};


class Solution2
{
public:
    bool isPalindrome(ListNode* head)
    {
        vector<int> st;
        ListNode *p = head;
        int counts = 0;
        while (p)
        {
            st.emplace_back(p->val);
            p = p->next;
            ++counts;
        }
        for (int i = 0, j = counts - 1; i < j; ++i, --j)
        {
            if (st[i] != st[j])
                return false;
        }
        return true;

    }
};

int main(void)
{

    return 0;
}
