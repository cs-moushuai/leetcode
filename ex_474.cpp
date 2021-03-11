#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string>& strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (const string &str : strs)
        {
            int num0 = count(str.begin(), str.end(), '0');
            int num1 = count(str.begin(), str.end(), '1');

            for (int i = m; i >= num0; i--)
            {
                for (int j = n; j >= num1; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - num0][j - num1] + 1);
                }
            }
        }
        return dp[m][n];

    }
};

int main(void)
{
    Solution obj;
    vector<string> strs = {"10", "0001", "111001", "1", "0"};
    cout << obj.findMaxForm(strs, 5, 3) << endl;

    return 0;
}
