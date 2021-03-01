#include <algorithm>
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int> menu;
        int len = nums.size();
        for (int i = 0; i < len; ++i)
        {
            if (menu.count(nums[i]) == 1)
                return nums[i];
            menu.emplace(nums[i]);

        }
        return 0;
    }
};


//class Solution
//{
//public:
//int findDuplicate(vector<int>& nums)
//{
//sort(nums.begin(), nums.end());
//int len = nums.size();
//for (int i = 1; i < len; ++i)
//{
//if (nums[i] == nums[i - 1])
//{
//return nums[i];
//}
//}
//return 0;
//}
//};

int main(void)
{

    return 0;
}
