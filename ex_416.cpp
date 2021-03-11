#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
#include <numeric>
#include <ostream>
#include <vector>

using namespace std;


class Solution
{
public:
    bool canPartition(vector<int>& nums)
    {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        int target = sum / 2;
        bool dp[target + 1];
        //for (auto &i: dp)
        //i = false;
        fill(dp, dp + target + 1, false);
        if (target >= nums[0])
        {
            dp[nums[0]] = 1;
        }
        for (auto k : dp)
            cout << k << " ";
        cout << endl;
        for (int i = 1; i < len; ++i)
        {
            for (int j = target; j >= 0; --j)
            {
                if (nums[i] == j)
                {
                    dp[j] = 1;
                }
                else if (nums[i] < j)
                {
                    dp[j] = dp[j] || dp[j - nums[i]];
                }
                //if (dp[target])
                    //return true;
            }
            for (auto k : dp)
                cout << k << " ";
            cout << endl;
        }
        return dp[target];
    }
};

class Solution2
{
public:
    bool canPartition(vector<int>& nums)
    {
        int len = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if ((sum & 1) == 1)
            return false;
        int target = sum / 2;
        vector<vector<int>> dp(len, vector<int>(target + 1, 0));
        if (target >= nums[0])
        {
            dp[0][nums[0]] = 1;
        }
        for (int i = 1; i < len; ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                dp[i][j] = dp[i - 1][j];
                if (nums[i] == j)
                {
                    dp[i][j] = 1;
                }
                else if (nums[i] < j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
                }
            }
        }
        return dp[len - 1][target];
    }
};

int main(void)
{
    Solution sy;
    vector<int> vec{1, 5, 11, 5};
    std::cout << sy.canPartition(vec) << endl;

    return 0;
}
