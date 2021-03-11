#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> result(numRows);
       for (size_t i = 0; i < numRows; i++)
       {
           result[i].resize(i+1);
           result[i].assign(i+1,1);
           for (size_t j = 1; j < i; j++)
           {
               result[i][j] = result[i-1][j] + result[i-1][j-1];
           }
           
       }
       return result;
        
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    sy.generate(5);
    return 0;
}
