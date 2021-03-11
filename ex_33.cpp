#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && target < nums[mid])
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }

            }
            else
            {
                if (nums[mid] < target && target <= nums[r])
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid - 1;
                }

            }
        }
        return -1;

    }
};

class Solution2
{
public:
    int search(vector<int>& nums, int target)
    {
        auto res = find(nums.begin(), nums.end(), target);
        return res != nums.end() ? res - nums.begin() : -1;
    }
};


int main(void)
{

    return 0;
}
