#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(grid[0]);
        for (int i = 1; i < n; ++i)
        {
            dp[i] += dp[i - 1];
        }
        for (int i = 1; i < m; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < n; ++j)
            {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }

        }
        return dp[n - 1];
    }
};

int main(void)
{
    Solution sy;
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << sy.minPathSum(grid) << endl;

    return 0;
}
