#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        // if(s.empty()&&t.empty())
        //     return true;
        // if(s.empty()||t.empty())
        //     return false;

        // if(s.size()!=t.size())
        //     return false;
        
        for(int i=0;i<s.size();i++)
        {
          if( s.find(s[i])!=t.find(t[i])) 
          return false;
        }
        return true;
       
    }
};

class Solution2
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> menu;

        for (size_t i = 0; i < s.length(); i++)
        {
            auto judge = menu.insert(pair<char, char>(s[i], t[i]));
            if (judge.second == false && menu[s[i]] != t[i])
            {
                return false;
            }
            
        }
        unordered_map<char, char> menu2;

        for (size_t i = 0; i < s.length(); i++)
        {
            auto judge = menu2.insert(pair<char, char>(t[i], s[i]));
            if (judge.second == false && menu2[t[i]] != s[i])
            {
                return false;
            }
            
        }

       return true; 

    }
};
// @lc code=end

int main(void)
{
    Solution sy;
    sy.isIsomorphic();
    return 0;
}
