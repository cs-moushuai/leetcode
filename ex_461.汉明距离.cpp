#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        int num = x ^ y;
        int count = 0;

        while(num != 0)
        {
            if(num % 2 == 1)
            {
                ++count;
            }
            num /= 2;
        }
        return count;

    }
};
// @lc code=end

int main(void)
{
    return 0;
}