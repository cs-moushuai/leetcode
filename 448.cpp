#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums)
    {
        if(nums.empty())
        {
            return vector<int>();
        }

        vector<int> result;
        sort(nums.begin(), nums.end());
        for(auto i = nums.cbegin(); i != nums.cend() - 1; i++)
        {
            if(*(i + 1) - *i != 1)
            {
                for(size_t j = 1; j < * (i + 1) - *i; j++)
                {
                    result.push_back(*i + j);
                }
            }
        }

        return result;

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
