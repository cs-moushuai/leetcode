#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        int max_price = prices[len - 1];
        int max_profit = 0;
        for (int i = len - 2; i >= 0; --i)
        {
            max_profit = max(max_profit, max(0, max_price - prices[i]));
            max_price = max(max_price, prices[i]);
        }
        return max_profit;
    }
};

int main(void)
{

    return 0;
}
