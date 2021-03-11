#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        for (int i = 0; i != n; i++)
        {
            nums1[i + m] = nums2[i];
        }

        sort(nums1.begin(), nums1.begin() + m + n);
    }
};

int main(void)
{
    Solution sy;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 7};

    sy.merge(nums1, 3, nums2, nums2.size());

    copy(nums1.cbegin(), nums1.cend(), ostream_iterator<int> (cout," "));
    cout<<endl;
    return 0;
}