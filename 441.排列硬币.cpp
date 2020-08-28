#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=441 lang=cpp
 *
 * [441] 排列硬币
 */

// @lc code=start
class Solution
{
public:
    int arrangeCoins(int n)
    {
        int i = 0;
        for (i = 1; i <= n; i++)
        {
            n -= i;
        }
        return i - 1;
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    cout << sy.arrangeCoins(5) << endl;
    return 0;
}