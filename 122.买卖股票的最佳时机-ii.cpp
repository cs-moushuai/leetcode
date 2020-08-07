#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int min = 0, max = 0, result = 0;


        bool flag = false; //flag == false, find the minium, == true, find the maxium
        for(auto i = prices.cbegin(); i != prices.cend(); i++)
        {
            if (flag == false && (i + 1 == prices.cend() || *i < *(i+1) ))
            {
                min = *i;
                flag = true;
            }
            else if(flag == true && (i + 1 == prices.cend() || *i > *(i+1) ))
            {
                max = *i;
                result += max - min;
                flag = false;
            }
            
        }
        return result;
    }
};
// @lc code=end

int main(void)
{
    return 0;
}