#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int len = s.size();
        int ans = 0;
        for (int center = 0; center < len * 2 + 1; ++center)
        {
            int left = center / 2;
            int right = left + center % 2;
            while (left >= 0 && right < len && s[left] == s[right])
            {
                --left;
                ++right;
                ++ans;
            }

        }
        return ans;
    }
};


class Solution2
{
public:
    int countSubstrings(string s)
    {
        int len = s.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int ans = 0;
        for (int j = 0; j < len; ++j)
        {
            for (int i = 0; i <= j; ++i)
            {
                if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    ++ans;
                }

            }
        }
        return ans;

    }
};

int main(void)
{

    return 0;
}
