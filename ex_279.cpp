#include <bits/stdc++.h>
#include <climits>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        queue<int> que;
        unordered_set<int> visited;
        int level = 0;
        que.push(n);
        while(!que.empty())
        {
            int len = que.size();
            ++level;
            for (int i = 0; i < len; ++i)
            {
                int curr = que.front();
                que.pop();
                for (int j = 1; j * j <= curr; ++j)
                {
                    int next = curr - j * j;
                    if (next == 0)
                        return level;
                    if (!visited.count(next))
                    {
                        que.push(next);
                        visited.emplace(next);
                    }
                }

            }
        }
        return -1;
    }
};


class Solution2
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j * j <= i; ++j)
            {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};

class Solution3
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            if (i * i <= n)
                dp[i * i] = 1;
            for (int j = 1; j <= i / 2; ++j)
            {
                dp[i] = min(dp[i], dp[j] + dp[i - j]);
            }
        }
        return dp[n];
    }
};

int main(void)
{
    Solution sy;
    cout << sy.numSquares(52) << endl;

    return 0;
}
