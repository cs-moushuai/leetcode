#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto res = equal_range(nums.begin(), nums.end(), target);

        if (res.first == res.second)
            return {-1, -1};
        int dis1 = res.first - nums.begin();
        int dis2 = res.second - nums.begin() - 1;
        return vector<int>{dis1, dis2};
    }
};

class Solution2
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);
        if (left == right)
            return {-1, -1};

        int dis1 = left - nums.begin();
        int dis2 = right - nums.begin() - 1;
        return vector<int>{dis1, dis2};
    }
};

class Solution3
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        if (!binary_search(nums.begin(), nums.end(), target))
        {
            return {-1, -1};
        }
        auto left = lower_bound(nums.begin(), nums.end(), target);
        auto right = upper_bound(nums.begin(), nums.end(), target);

        int dis1 = left - nums.begin();
        int dis2 = right - nums.begin() - 1;
        return vector<int>{dis1, dis2};
    }
};

int main(void)
{
    Solution sy;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    auto res = sy.searchRange(nums, 8);
    cout << res[0] << "," << res[1] << endl;

    return 0;
}
