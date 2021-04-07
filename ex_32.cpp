#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<pair<char, int>> st;
        int len = s.size();
        for (int i = 0; i < len; ++i)
        {
            if (!st.empty() && s[i] == ')' && st.top().first == '(')
            {
                st.pop();
            }
            else
            {
                st.push({s[i], i});
            }
        }
        vector<int> flag(len, 0);
        while (!st.empty())
        {
            auto tmp = st.top();
            st.pop();
            flag[tmp.second] = 1;
        }
        int sum = 0;
        int max_len = 0;
        for (const auto &i : flag)
        {
            if (i == 1)
            {
                sum = 0;
            }
            else
            {
                ++sum;
                max_len = max(max_len, sum);
            }
        }
        return max_len;
    }
};

int main(void)
{

    return 0;
}
