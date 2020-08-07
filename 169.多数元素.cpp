#include <bits/stdc++.h>

using namespace std;
/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> menu;
        for (auto &i : nums)
        {
            menu[i]++;
        }
        auto result = max_element(
            menu.cbegin(), menu.cend(), [](const pair<const int, int> &a, const pair<const int, int> &b) -> bool {
                return a.second < b.second;
            });

        return result->first;
    }
};
// @lc code=end

int main(void)
{
    return 0;
}