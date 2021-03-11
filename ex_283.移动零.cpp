#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        for (; fast < nums.size(); fast++)
        {
            if (nums[fast] != 0)
            {
                nums[slow] = nums[fast];

                if (slow != fast)
                {
                    nums[fast] = 0;
                }
                slow++;
            }
        }
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    vector<int> v = {0, 1, 0, 3, 12};
    sy.moveZeroes(v);
    return 0;
}