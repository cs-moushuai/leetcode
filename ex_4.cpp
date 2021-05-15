#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
    }
};

class Solution2
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> merg = nums1;
        for (auto &i : nums2)
        {
            merg.emplace_back(i);
        }
        sort(merg.begin(), merg.end());
        int len = merg.size();
        int middle = len / 2;
        return len % 2 == 0 ? (merg[middle] + merg[middle-1])/2.0 : merg[middle];
    }
};

int main(void)
{
    Solution sy;
    vector<int> nums1 = {};
    vector<int> nums2 = {2};
    std::cout << sy.findMedianSortedArrays(nums1, nums2) << std::endl;

    return 0;
}
