#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */

// @lc code=start
class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        /*         auto findNums = [](vector<int>::iterator i) -> int {
                         if(*(i+1)-*i != 1)
            {
                return *i + 1;
            } 
            return 0;
        };

        auto result = for_each(nums.begin(), nums.end(), findNums); */
        for(size_t i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)
            {
                return i;
            }
        }
        return nums.size();
    }
};
// @lc code=end

int main(void)
{
    return 0;
}