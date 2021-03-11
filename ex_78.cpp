#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<vector<int>> res;
public:
    void Func(vector<int> &oneset, const vector<int> &nums, int start, int end, int select)
    {
        if (!select)
        {
            res.emplace_back(oneset);
            return;
        }
        for (int i = start; i < end; ++i)
        {
            vector<int> tmp = oneset;
            oneset.emplace_back(nums[i]);
            Func(oneset, nums, i + 1, end, select - 1);
            oneset = tmp;

        }

    }
    vector<vector<int>> subsets(vector<int>& nums)
    {
        //res.push_back({});
        int len = nums.size();
        for (int i = 0; i <= len; ++i)
        {
            vector<int> oneset = {};
            Func(oneset, nums, 0, len, i);

        }
        return res;
    }
};

int main(void)
{
    vector<int> vec{1, 2, 3};
    Solution sy;
    auto res = sy.subsets(vec);
    for (auto &i : res)
    {
        for (auto &j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
