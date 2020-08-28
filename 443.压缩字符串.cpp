#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */

// @lc code=start
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int n_count = 0;
        string s_count;

        vector<char>::iterator i, j;
        for (i = chars.begin(); i != chars.end();)
        {
            n_count = 1;
            for (j = i + 1; j != chars.end() && *j == *i; j++)
            {
                n_count++;
            }
            if (n_count > 1)
            {
                i = chars.erase(i + 1, j);
                s_count = to_string(n_count);
                for (auto ch : s_count)
                {
                    i = chars.insert(i, ch);
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        return chars.size();
    }
    /*     int compress(vector<char> &chars)
    {
        vector<char> map;
        int n_count = 0;
        string s_count;

        vector<char>::iterator i, j;
        for(i = chars.begin(); i != chars.end(); i = j)
        {
            n_count = 1;
            for(j = i + 1; j != chars.end() && *j == *i; j++)
            {
                n_count++;
            }
            map.push_back(*i);
            if(n_count > 1)
            {
                s_count = to_string(n_count);
                for(auto ch: s_count)
                {
                    map.push_back(ch);
                }
            }
        }
        chars = map;
        return chars.size();
    } */
};

// @lc code=end

int main(void)
{
    vector<char> v = {'a', 'b', 'b', 'b', 'b', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c', 'c'};
    Solution sy;
    cout << sy.compress(v) << endl;
    return 0;
}