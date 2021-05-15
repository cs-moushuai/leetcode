#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> arr;
        for (auto &i : nums)
        {
            arr.emplace(i);
        }
        int longestlen = 0;
        for (const auto &i : arr)
        {
            int currlen = 1;
            int currnum = i;
            if (!arr.count(i - 1))
            {
                while (arr.count(currnum + 1))
                {
                    currnum++;
                    currlen++;
                }

            }
            longestlen = max(longestlen, currlen);
        }
        return longestlen;

    }
};

class Solution2
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        int len = nums.size();
        if (len == 0)
            return 0;
        vector<int> dp(len, 1);
        for (int i = 1; i < len; ++i)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                dp[i] = dp[i - 1] + 1;
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

int main(void)
{

    return 0;
}
