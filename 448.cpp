#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        if (nums.empty())
            return {};
        int len = nums.size();
        vector<int> vec(len + 1);
        for (auto i : nums)
        {
            vec[i]++;
        }
        vector<int> res;
        for (int i = 1; i < len + 1; ++i)
        {
            if (vec[i] == 0)
                res.emplace_back(i);
        }
        return res;
    }
};

int main(void)
{
    Solution sy;
    vector<int> nums = {1, 3, 4, 5, 3, 6, 8};
    auto result = sy.findDisappearedNumbers(nums);
    ostream_iterator<int> output(cout, " ");
    copy(result.cbegin(), result.cend(), output);
    cout << endl;

    return 0;
}
