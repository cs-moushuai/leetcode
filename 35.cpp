#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (target <= nums[i])
            {
                return i;
            }
        }

        return nums.size();
    }
};

int main(void)
{
    Solution sy;
    vector<int> v = {0, 1, 2, 5};
    cout << sy.searchInsert(v, 6) << endl;
    return 0;
}