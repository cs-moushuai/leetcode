#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=258 lang=cpp
 *
 * [258] 各位相加
 */

// @lc code=start
class Solution {
public:
    int addDigits(int num) 
    {
        if( num / 10 == 0)
        {
            return num;
        }

        int sum = 0;
        while (num != 0)
        {
            sum += num % 10;
            num /= 10;
        }
        return addDigits(sum);
        
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    cout<<sy.addDigits(38)<<endl;
    return 0;
}