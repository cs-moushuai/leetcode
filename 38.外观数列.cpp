#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
class Solution {
public:
    string countAndSay(int n) 
    {
        string preview = "1", now;
        for(int i = 1; i < n; i++)    
        {
            int count = 0;
            for(auto j = preview.cbegin(); j <= preview.cend(); j++)
            {
                if( j != preview.cend() &&
                (j == preview.cbegin() || *j == *(j-1)) )
                {
                    count++;
                }
                else
                {
                    now += to_string(count) + *(j-1);
                    count = 0;
                    if( ( j != preview.cend() && *j != *(j-1)))
                    {
                        count++;
                    }
                }
                
            }
            preview = now;
            now.clear();
        }
        return preview;
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    cout<<sy.countAndSay(4)<<endl;
    return 0;
}