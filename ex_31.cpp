#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int>& nums)
    {
        int len = nums.size();
        bool flag = false;
        for (int i = len - 1; i >= 1; --i)
        {
            if (nums[i] > nums[i - 1])
            {
                int min_index = i;
                for (int j = i + 1; j < len; ++j)
                {
                    if (nums[j] > nums[i - 1] && nums[j] < nums[min_index])
                        min_index = j;
                }
                swap(nums[min_index], nums[i - 1]);
                sort(nums.begin() + i, nums.end());
                flag = true;
                break;
            }

        }
        if (!flag)
        {
            reverse(nums.begin(), nums.end());
        }
    }
};

int main(void)
{

    return 0;
}
