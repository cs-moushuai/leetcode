#include <bits/stdc++.h>
#include <stdexcept>
#include <vector>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int m = s.size();
        int n = wordDict.size();
        vector<int> len_words;
        for (const auto &i : wordDict)
        {
            len_words.emplace_back(i.size());
        }
        //vector<deque<bool>> dp(m, deque<bool>(n, false));
        deque<bool> dp(m + 1, false);
        //fill(dp[0].begin(), dp[0].end(), true);
        dp[0] = true;
        for (int i = 1; i < m + 1; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i - len_words[j] < 0)
                    continue;
                bool flag = dp[i - len_words[j]];
                if (flag && string(s.begin() + i - len_words[j], s.begin() + i) == wordDict[j])
                {
                    dp[i] = true;
                }
            }

        }
        return dp[m];
    }
};

int main(void)
{
    Solution sy;
    vector<string> data{"leet", "code"};
    std::cout << sy.wordBreak("leetcode", data) << std::endl;

    return 0;
}
