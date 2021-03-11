#include <bits/stdc++.h>

using namespace std;


class Solution2
{
public:
    int rob(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return nums[0];
        int ifirst = nums[0];
        int isecond = max(nums[0], nums[1]);
        for (int i = 2; i < len; ++i)
        {
            int tmp = isecond;
            isecond = max(ifirst + nums[i], isecond);
            ifirst = tmp;
        }
        return isecond;

    }
};
class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 0)
            return 0;
        else if (len == 1)
            return nums[0];
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);

        }
        return dp[len - 1];

    }
};

int main(void)
{

    return 0;
}
