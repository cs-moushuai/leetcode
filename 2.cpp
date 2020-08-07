#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

// * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    /*     ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int num1 = 0, num2 = 0;
        vector<int> v1, v2;
        for (ListNode *p = l1; p != nullptr; p = p->next)
        {
            v1.push_back(p->val);
        }
        for (ListNode *p = l2; p != nullptr; p = p->next)
        {
            v2.push_back(p->val);
        }

        // copy(v1.cbegin(), v1.cend(), ostream_iterator<int>(cout, ","));
        // cout << endl;
        // copy(v2.cbegin(), v2.cend(), ostream_iterator<int>(cout, ","));
        // cout << endl;

        for (auto i = v1.rbegin(); i != v1.rend(); i++)
        {
            num1 = num1 * 10 + *i;
        }
        for (auto i = v2.rbegin(); i != v2.rend(); i++)
        {
            num2 = num2 * 10 + *i;
        }

        // cout << num1 << "," << num2 << endl;

        int sum = num1 + num2;
        ListNode *result, *node, *end;
        string str = to_string(sum);
        bool flag = false;
        for (auto i = str.rbegin(); i != str.rend(); i++)
        {
            node = new ListNode(*i - '0');
            if (flag == false)
            {
                result = end = node;
                flag = true;
            }
            else
            {
                end->next = node;
                end = node;
            }
        }
        vector<int> v3;
        for (ListNode *p = result; p != nullptr; p = p->next)
        {
            v3.push_back(p->val);
        }

        copy(v3.cbegin(), v3.cend(), ostream_iterator<int>(cout, ","));
        cout << endl;

        return result;
    } */
    string stringSum(string s1, string s2)
    {
        int carry = 0, value = 0;
        int size_diff = 0;

        if (s1.length() > s2.length())
        {
            size_diff = s1.length() - s2.length();
            //    size_max = s1.length();

            reverse(s2.begin(), s2.end());
            s2.append(size_diff, '0');
            reverse(s2.begin(), s2.end());
        }
        else if (s1.length() < s2.length())
        {
            size_diff = s2.length() - s1.length();
            //    size_max = s2.length();

            reverse(s1.begin(), s1.end());
            s1.append(size_diff, '0');
            reverse(s1.begin(), s1.end());
        }

        string sum;

        for (auto s1_iter = s1.rbegin(), s2_iter = s2.rbegin(); s1_iter != s1.rend(); s1_iter++, s2_iter++) //in this time,s1 and s2 have same length
        {
            value = *s1_iter + *s2_iter - 2 * '0' + carry;
            carry = value / 10;
            sum += value % 10 + '0';
        }

        if (carry == 1)
        {
            sum += '1';
        }

        reverse(sum.begin(), sum.end());

        return sum;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        string s1, s2;
        for (ListNode *p = l1; p != nullptr; p = p->next)
        {
            s1 += p->val + '0';
        }
        for (ListNode *p = l2; p != nullptr; p = p->next)
        {
            s2 += p->val + '0';
        }
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        cout << s1 + "+" + s2 + "=";

        // copy(v1.cbegin(), v1.cend(), ostream_iterator<int>(cout, ","));
        // cout << endl;
        // copy(v2.cbegin(), v2.cend(), ostream_iterator<int>(cout, ","));
        // cout << endl;

        ListNode *result, *node, *end;
        string str = stringSum(s1, s2);
        cout << str << endl;
        bool flag = false;
        for (auto i = str.rbegin(); i != str.rend(); i++)
        {
            node = new ListNode(*i - '0');
            if (flag == false)
            {
                result = end = node;
                flag = true;
            }
            else
            {
                end->next = node;
                end = node;
            }
        }
        vector<int> v3;
        for (ListNode *p = result; p != nullptr; p = p->next)
        {
            v3.push_back(p->val);
        }

        copy(v3.cbegin(), v3.cend(), ostream_iterator<int>(cout, " "));
        cout << endl;

        return result;
    }
};

ListNode *CreateList()
{
    int num = 0;
    ListNode *lend, *node;

    cin >> num;
    node = new ListNode(num);
    ListNode *head = node;
    lend = node;

    while (cin >> num)
    {
        node = new ListNode(num);
        lend->next = node;
        lend = node;
    }

    return head;
}

void freeList(ListNode *head)
{
    ListNode  *p = head, *q;
    while (p)
    {
        q = p; //q保存bai当du前zhi的daop
        p = p->next;
        free(q);
    }
}

int main(void)
{
    Solution sy;
    ListNode *l1, *l2;
    cout << "l1:";

    l1 = CreateList();
    cin.clear();
    clearerr(stdin);
    cout << "l2:";
    l2 = CreateList();
    cin.clear();
    clearerr(stdin);

    sy.addTwoNumbers(l1, l2);
    freeList(l1);
    freeList(l2);

    return 0;
}