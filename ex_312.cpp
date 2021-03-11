#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCoins(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> val(len + 2);
        val[0] = val[len + 1] = 1;
        for (int i = 0; i < len; ++i)
        {
            val[i + 1] = nums[i];
        }

        vector<vector<int>> dp(len + 2, vector<int> (len + 2));

        for (int i = len - 1; i >= 0; i--)
        {
            for (int j = i + 2; j <= len + 1; j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i][j], val[i] * val[k] * val[j] + dp[i][k] + dp[k][j]);
                    //int sum = val[i] * val[k] * val[j];
                    //sum += dp[i][k] + dp[k][j];
                    //dp[i][j] = max(dp[i][j], sum);
                }
            }
        }
        return dp[0][len + 1];
    }
};

int main(void)
{

    return 0;
}
