#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        int l = 1, r = 2;
        int t = 0;
        for (int i = 3; i < n + 1; ++i)
        {
            t = l + r;
            l = r;
            r = t;
        }
        return t;
    }
};



class Solution2
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(void)
{

    return 0;
}
