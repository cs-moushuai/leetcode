#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        unordered_map<int, int> mp;
        int pre = 0;
        int counts = 0;
        mp[0] = 1;
        for (const auto &i : nums)
        {
            pre += i;
            if (mp.find(pre - k) != mp.end())
            {
                counts += mp[pre-k];
            }
            ++mp[pre];

        }
        return counts;
    }
};

class Solution2
{
public:
    int subarraySum(vector<int>& nums, int k)
    {
        int len = nums.size();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] == k)
                ++ans;
            dp[i][i] = nums[i];
        }
        for (int j = 1; j < len; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (dp[i][j] == k)
                    ++ans;
            }
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
