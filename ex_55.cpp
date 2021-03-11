#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int len = nums.size();
        int rightmost = 0;
        for (int i = 0; i < len; ++i)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= len - 1)
                    return true;
            }

        }
        return false;
    }
};


class Solution2
{
public:
    bool canJump(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> flag(len, 0);
        flag[0] = 1;
        for (int i = 0; i < len; ++i)
        {
            if (flag[i])
            {
                for (int j = nums[i]; j > 0; --j)
                {
                    if (i + j < len)
                        flag[i + j] = 1;
                }
            }

        }
        return flag[len - 1];
    }
};

int main(void)
{

    return 0;
}
