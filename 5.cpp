#include <bits/stdc++.h>
#include <bits/types/siginfo_t.h>
#include <cstddef>
#include <functional>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len < 2)
            return s;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
        {
            dp[i][i] = 1;
        }
        int max_len = 1;
        int begin = 0;
        for (int j = 1; j < len; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (s[i] != s[j])
                {
                    dp[i][j] = 0;
                }
                else
                {
                    if ((j - 1) - (i + 1) + 1 < 2)
                    {
                        dp[i][j] = 1;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }
                if (j - i + 1 > max_len && dp[i][j])
                {
                    max_len = j - i + 1;
                    begin = i;
                }
            }
        }
        return s.substr(begin, max_len);
    }
};

class Solution3
{
private:
    int len = 0;
    string centerSpread(string &s, int i, int j)
    {
        while (i >= 0 && j < len && s[i] == s[j])
        {
            --i;
            ++j;
        }
        return s.substr(i + 1, j - i + 1 - 2);

    }


public:
    string longestPalindrome(string s)
    {
        len = s.size();
        if (len < 2)
            return s;
        int max_len = 0;
        string res;

        for (int i = 1; i < len - 1; ++i)
        {
            string oddspread = centerSpread(s, i, i);
            string evenspread = centerSpread(s, i, i + 1);
            string max_len_str = oddspread.size() > evenspread.size() ? oddspread : evenspread;
            if (max_len_str.size() > max_len)
            {
                max_len = max_len_str.size();
                res = max_len_str;
            }

        }
        return res;
    }
};

class Solution2
{
private:
    int head = 0, tail = 0;
    int len = 0;
public:
    bool checkSubstring(const string &s, int start, int end)
    {
        for (; start < end; ++start, --end)
        {
            if (s[start] != s[end])
                return false;
        }
        return true;
    }
    void Dfs(const string &str, int start, int end)
    {
        int tmp_len = end - start + 1;
        if (tmp_len > len && checkSubstring(str, start, end))
        {
            head = start;
            tail = end;
            len = tmp_len;
        }
        if (start == end)
            return;
        Dfs(str, start, end - 1);
        Dfs(str, start + 1, end);
    }
    string longestPalindrome(string s)
    {

        int s_len = s.size();
        if (s_len == 1 || checkSubstring(s, 0, s_len - 1))
            return s;
        Dfs(s, 0, s_len - 1 - 1);
        Dfs(s, 1, s_len - 1);

        return string(s.begin() + head, s.begin() + tail + 1);
    }
};

int main(void)
{
    Solution sy;
    //std::cout << sy.checkSubstring("abba", 0, 3) << std::endl;

    return 0;
}
