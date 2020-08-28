#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution
{
public:
    bool isPalindrome(string s)
    {
        string str;
        for(auto i: s)
        {
            if (isalnum(i))
            {
                if (isupper(i))
                {
                    i = tolower(static_cast<int>(i));
                }
                str += i;
            }
            
        }
        /*
        auto head = str.begin();
        auto rhead = str.end() - 1;
        for(; head < rhead; head++,rhead--)
        {
            if (*head != *rhead)
            {
                return false;
            }
        }

        return true;
        */
       string rstr(str.rbegin(),str.rend());
       return str == rstr;
    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    cout<<sy.isPalindrome("eio");

    return 0;
}
