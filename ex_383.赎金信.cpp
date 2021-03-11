#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
class Solution
{
public:
/*     bool canConstruct(string ransomNote, string magazine)
    {
        unordered_map<char, int> rasnsom, magz;

        for(auto i: ransomNote)
        {
            rasnsom[i]++;
        }
        for(auto i: magazine)
        {
            magz[i]++;
        }
        for(auto i = rasnsom.cbegin(); i != rasnsom.cend(); i++)
        {
            if(i->second > magz[i->first])
            {
                return false;
            }
        }

        return true;
        }*/
      bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for (char c : magazine) hash[c - 'a'] += 1;
        for (char c : ransomNote) 
            if ((hash[c - 'a'] -= 1) < 0) return false;
        return true;
    }
};
// @lc code=end

int main(void)
{
    return 0;
}