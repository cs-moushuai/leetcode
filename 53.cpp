#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> max;

        for (auto i = nums.cbegin(); i != nums.cend(); i++)
        {
            int each_max = *i;
            int tmp = each_max;
            for (auto j = i + 1; j != nums.cend(); j++)
            {
                tmp = tmp + *j;
                if (tmp > each_max)
                {
                    each_max = tmp;
                }
            }

            max.push_back(each_max);
        }

        auto result = max_element(max.cbegin(), max.cend());
        return *result;
    }
};

int main(void)
{
    Solution sy;
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sy.maxSubArray(v) << endl;
    return 0;
}
