#include <bits/stdc++.h>
#include <functional>

using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k];
    }
};

int main(void)
{

    return 0;
}
