#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <ratio>
#include <vector>

using namespace std;


class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int len = nums.size();
        int min_val = INT_MAX, max_val = INT_MIN;
        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
                min_val = min(min_val, nums[i + 1]);
        }
        for (int i = len - 1; i > 0; --i)
        {
            if (nums[i] < nums[i - 1])
                max_val = max(max_val, nums[i - 1]);
        }
        int left = 0, right = -1;
        for (left = 0; left < len; ++left)
        {
            if (nums[left] > min_val)
                break;
        }
        for (right = len - 1; right >= 0; --right)
        {
            if (nums[right] < max_val)
                break;
        }
        return right - left < 0 ? 0 : right - left + 1;
    }
};

class Solution5
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        vector<int> extra = nums;
        sort(extra.begin(), extra.end());
        bool flag = false;
        int len = nums.size();
        int left = len - 1, right = len - 1;
        for (int i = 0; i < len; ++i)
        {
            if (nums[i] != extra[i])
            {
                if (!flag)
                    left = i;
                else
                    right = i;
                flag = true;
            }

        }
        return right - left + 1;
    }
};

class Solution3
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int len = nums.size();

        int left = len;
        int right = 0;
        bool flag = false;
        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (!flag)
                {
                    left = i;
                    flag = true;
                }
                auto tmp = find_if(nums.begin() + i + 1, nums.end(), [&](const int &j)
                {
                    if (j >= nums[i])
                        return true;
                    return false;
                });
                right = max(int(tmp - nums.begin() - 1), right);
            }
        }
        cout << "left: " << left << " right: " << right << endl;
        if (flag == false)
            return 0;
        int left2 = len;
        int right2 = len - 1;
        flag = false;
        for (int i = len - 1; i > 0; --i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (!flag)
                {
                    right2 = i;
                    flag = true;
                }
                bool flag2 = false;
                for (int j = i - 1; j >= 0; --j)
                {
                    if (nums[j] <= nums[i])
                    {
                        left2 = min(left2, j + 1);
                        flag2 = true;
                        break;
                    }
                }
                if (!flag2)
                    left2 = 0;
            }
        }
        cout << "left2: " << left2 << " right2: " << right2 << endl;
        if (flag == false)
            return right - left + 1;
        return max(right2, max(right, max(left, left2))) - min(left, min(left2, min(right, right2))) + 1;
    }
};

class Solution2
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int len = nums.size();

        int left = 0, right = len - 1;
        int left_right = len - 1, right_left = 0;
        bool flag = false;
        for (int i = 0; i < len - 1; ++i)
        {
            if (nums[i] > nums[i + 1])
            {
                if (!flag)
                {
                    left = i;
                    flag = true;
                }
                auto tmp = find_if(nums.begin() + left + 1, nums.end(), [&](const int &j)
                {
                    if (j >= nums[i])
                        return true;
                    return false;
                });
                left_right = tmp - nums.begin() - 1;
            }
        }
        cout << "left: " << left << " left_right: " << left_right << endl;
        flag = false;
        for (int i = len - 1; i > 0; --i)
        {
            if (nums[i] < nums[i - 1])
            {
                if (!flag)
                {
                    right = i;
                    flag = true;
                }
                for (int j = i; j >= 0; --j)
                {
                    if (nums[j] <= nums[i])
                        right_left = j + 1;
                }
            }
        }
        cout << "right: " << right << " right_left: " << right_left << endl;
        //if (left_right <= right_left || )
        if (left_right < right_left)
        {
            return (left_right - left + 1) + (right - right_left + 1);
        }
        else if (left < right)
        {
            return right - left + 1;
        }
        else if(right < left)
        {
            return (right - right_left + 1) + (left_right - left + 1);
        }
        else
        {
            return left_right - right_left + 1;
        }
    }
};

int main(void)
{
    vector<int> data = {1, 2, 3, 5, 4};
    Solution sy;
    std::cout << sy.findUnsortedSubarray(data) << std::endl;

    return 0;
}
