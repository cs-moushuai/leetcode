#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 2)
            return {nums[1], nums[0]};
        vector<int> res = nums;

        int left = 1;
        for (int i = 1; i < len; ++i)
        {
            int tmp = left * res[i];
            res[i] = left;
            left = tmp;
        }
        int right = 1;
        for (int i = len - 2; i >= 0; --i)
        {
            right *= nums[i + 1];
            res[i] *= right;
        }

        return res;
    }
};



class Solution2
{
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int len = nums.size();
        if (len == 2)
            return {nums[1], nums[0]};
        vector<int> res = nums;

        for (int i = 1; i < len; ++i)
        {
            res[i] *= res[i - 1];
        }
        res.pop_back();
        res.insert(res.begin(), 1);
        int right = 1;
        for (int i = len - 2; i >= 0; --i)
        {
            right *= nums[i + 1];
            res[i] *= right;
        }

        return res;
    }
};

int main(void)
{
    Solution sy;
    vector<int> vec = {1, 2, 3, 4};
    auto res = sy.productExceptSelf(vec);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
