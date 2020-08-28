#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=389 lang=cpp
 *
 * [389] 找不同
 */

// @lc code=start
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
/*         for (size_t i = 0; ; i++)
        {
            if( i == s.length() || s[i] != t[i])
            {
               return t[i];
            }
        } */
        
        return accumulate(t.begin(), t.end(), 0) - accumulate(s.begin(), s.end(), 0);
    }
};
// @lc code=end

int main(void)
{

    return 0;
}