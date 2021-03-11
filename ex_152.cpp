#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int len = nums.size();
        int max_v = nums[0], min_v = nums[0];
        int ans = nums[0];
        for (int i = 1; i < len; ++i)
        {
            int tmp_max = max_v, tmp_min = min_v;
            max_v = max(nums[i], max(tmp_max * nums[i], tmp_min * nums[i]));
            min_v = min(nums[i], min(tmp_max * nums[i], tmp_min * nums[i]));
            ans = max(max_v, ans);
        }
        return ans;
    }
};

class Solution3
{
public:
    int maxProduct(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> max_v(nums), min_v(nums);
        int ans = nums[0];
        for (int i = 1; i < len; ++i)
        {
            max_v[i] = max(nums[i], max(max_v[i - 1] * nums[i], min_v[i - 1] * nums[i]));
            min_v[i] = min(nums[i], min(max_v[i - 1] * nums[i], min_v[i - 1] * nums[i]));
            ans = max(max_v[i], ans);
        }
        return ans;
    }
};

class Solution2
{
public:
    int maxProduct(vector<int> &nums)
    {
        int len = nums.size();
        int max_v = 1, min_v = 1;
        int ans = INT_MIN;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] < 0)
                swap(max_v, min_v);
            max_v = max(max_v * nums[i], nums[i]);
            min_v = min(min_v * nums[i], nums[i]);
            ans = max(max_v, ans);
        }
        return ans;
    }
};

int main(void)
{

    return 0;
}
