#include <iostream>
#include <vector>

using namespace std;
/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        for (auto num = nums.begin(); num != nums.end(); num++)
        {
            if (*num == val)
            {
                nums.erase(num--);
            }
        }

        return nums.size();
    }
};
// @lc code=end
int main(void)
{
    Solution sy;
    vector<int> v = {2, 3, 4, 2};
    cout << sy.removeElement(v, 2) << endl;
    return 0;
}

