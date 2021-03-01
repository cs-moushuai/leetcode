#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> dp(len, 1);
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
