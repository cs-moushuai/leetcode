#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int res;
        for (const auto &i: nums)
        {
            res ^= i;
        }
        return res;
    }
};



class Solution2
{
public:
    int singleNumber(vector<int>& nums)
    {
        unordered_map<int, int> menu;

        for(const auto &i : nums)
        {
            ++menu[i];
        }

        auto iter = find_if(menu.begin(), menu.end(), [](pair<int, int> i)
        {
            if(i.second == 1)
                return true;
            return false;
        });

        return iter->first;


    }
};


int main(void)
{
    return 0;
}
