#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        s = " " + s;
        p = " " + p;
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<int>> dp(s_len + 1, vector<int>(p_len + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= s_len; ++i)
        {
            for (int j = 1; j <= p_len; ++j)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                    {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                    }
                    else
                    {
                        dp[i][j] = dp[i][j - 2];
                    }

                }
            }
        }
        return dp[s_len][p_len];

    }
};

class Solution3
{
private:
    int s_len, p_len;
    int Dfs(string &s, int textptr, char c)
    {
        if (s[textptr] != c || textptr >= s_len)
        {
            return textptr;
        }
        return Dfs(s, textptr + 1, c);
    }
public:
    bool isMatch(string s, string p)
    {
        int textptr = 0, pattptr = 0;
        s_len = s.size();
        p_len = p.size();
        for (; textptr < s_len && pattptr < p_len;)
        {
            if (pattptr < p_len - 1 && p[pattptr + 1] == '*')
            {

                if (p[pattptr] == '.')
                {
                    pattptr += 2;
                    while (pattptr < p_len - 1 && p[pattptr + 1] == '*')
                    {
                        pattptr += 2;
                    }
                    if (pattptr >= p_len)
                        return true;
                    return false;
                }
                textptr = Dfs(s, textptr, p[pattptr]);
                if (textptr == s_len)
                    return true;
                pattptr += 2;
                continue;
            }
            if (s[textptr] == p[pattptr])
            {
            }
            else if (p[pattptr] == '.')
            {
            }
            else
            {
                return false;
            }
            ++textptr;
            ++pattptr;
        }
        if (textptr == s_len && pattptr == p_len)
            return true;
        else if (textptr < s_len)
            return false;
        else if (pattptr < p_len)
        {
            while (pattptr < p_len - 1 && p[pattptr + 1] == '*')
            {
                pattptr += 2;
            }
            if (pattptr == p_len)
                return true;
            return false;
        }
        else
        {
            return false;
        }

    }
};

int main(void)
{
    Solution sy;
    cout << sy.isMatch("bbbba", ".*a*a") << endl;

    return 0;
}
