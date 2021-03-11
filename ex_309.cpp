#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int len = prices.size();
        int hold, unhold_cool, unhold_uncool;

        hold = -prices[0];
        unhold_cool = unhold_uncool = 0;
        for (int i = 1; i < len; ++i)
        {
            int t_hold = hold, t_unhold_cool = unhold_cool, t_unhold_uncool = unhold_uncool;

            hold = max(t_hold, t_unhold_uncool - prices[i]);
            unhold_cool = t_hold + prices[i];
            unhold_uncool = max(t_unhold_cool, t_unhold_uncool);
        }
        return max(unhold_cool, unhold_uncool);
    }
};

class Solution3
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.empty())
        {
            return 0;
        }
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(3));

        dp[0][0] = -prices[0];
        dp[0][1] = dp[0][2] = 0;
        for (int i = 1; i < len; ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
        }
        return max(dp[len - 1][1], dp[len - 1][2]);
    }
};

class Solution2
{
public:
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        vector<vector<int>> dp(len, vector<int>(4, -1));
        int my_cost = 0;

        dp[0][0] = 0;
        dp[0][1] = prices[0];
        my_cost -= prices[0];
        for (int i = 1; i < len; ++i)
        {
            dp[i][0] =  max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][3]));
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][3]);
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) - 1 + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        for (auto &i : dp)
        {
            for (auto &j : i)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        auto money = max_element(dp[len - 1].begin(), dp[len - 1].end());
        return *money - my_cost;
    }
};

int main(void)
{
    Solution sy;
    vector<int> prices = {1, 2, 3, 0, 2};
    std::cout << sy.maxProfit(prices) << std::endl;

    return 0;
}
