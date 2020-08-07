#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
/*     uint32_t reverseBits(uint32_t n) 
    {
        uint32_t result = 0;
        uint32_t order_code = pow(2,31);
        

        do
        {
            result += (n % 2) * order_code;
            order_code /= 2;
        } while ((n /= 2) != 0);
        
       return result; 
    } */
    uint32_t reverseBits(uint32_t n) 
    {
       uint32_t result = 0;
       int i = 32; 

        while (i--)
        {
            result <<= 1;
            result += n&0x1;
            n >>= 1;
        }
        

       return result; 
    }
    
};
// @lc code=end

int main(void)
{
    return 0;
}