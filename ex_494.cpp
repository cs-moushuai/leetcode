#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int len = nums.size();
        vector<int> dp(2001, 0);

        dp[nums[0] + 1000] = 1;
        dp[-nums[0] + 1000] += 1;
        for (int i = 1; i < len; ++i)
        {
            vector<int> next(2001, 0);
            for (int sum = -1000; sum <= 1000; ++sum)
            {
                if (dp[sum + 1000] > 0)
                {
                    next[sum + nums[i] + 1000] += dp[sum + 1000];
                    next[sum - nums[i] + 1000] += dp[sum + 1000];
                }
            }
            dp = next;
        }
        return S > 1000 ? 0 : dp[S + 1000];

    }
};

class Solution2
{
public:
    int findTargetSumWays(vector<int>& nums, int S)
    {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(2001, 0));

        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] += 1;
        for (int i = 1; i < len; ++i)
        {
            for (int sum = -1000; sum <= 1000; ++sum)
            {
                if (dp[i - 1][sum + 1000] > 0)
                {
                    dp[i][sum + nums[i] + 1000] += dp[i - 1][sum + 1000];
                    dp[i][sum - nums[i] + 1000] += dp[i - 1][sum + 1000];
                }
            }
        }
        return S > 1000 ? 0 : dp[len - 1][S + 1000];

    }
};

int main(void)
{

    return 0;
}
