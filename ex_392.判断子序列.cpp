#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        auto head = t.begin();
        for (size_t i = 0; i < s.size(); i++)
        {
            head = find(head, t.end(), s[i]);
            if(head == t.end())
            {
                return false;
            }
            head++;
            // cout<<t.end()-head<<endl;
        }
        
        return true;
        
    }
};
// @lc code=end
int main(void)
{
    Solution sy;
    cout<<sy.isSubsequence("aaaaa", "bbaaaa")<<endl;
    return 0;
}

