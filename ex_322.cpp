#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;


class Solution
{
public:
    int coinChange(vector<int>& coins, int amount)
    {
        int len = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < len; ++j)
            {
                if (i >= coins[j])
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }
};

//class Solution
//{
//public:
//int coinChange(vector<int>& coins, int amount)
//{
//sort(coins.begin(), coins.end());
//int counts = 0;
//for (int i = coins.size() - 1; i >= 0; --i)
//{
//int tmp = amount / coins[i];
//if (tmp == 0)
//continue;
//counts += tmp;
//amount -= tmp * coins[i];
//}
//if (amount != 0)
//return -1;
//return counts;

//}
//};

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << 123 << std::endl;
        continue;
    }

    return 0;
}
