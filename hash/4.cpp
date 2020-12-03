#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        map<int, int> menu;

        for(auto i : nums)
        {
            menu[i]++;
        }

        auto iter = find_if(menu.begin(), menu.end(), [](pair<int, int> i)
        {
            if(i.second == 1) return true;
            return false;
        });

        return iter->second;


    }
};

int main(void)
{
    Solution sy;
    vector<int> v = {4, 1, 2, 1, 2};
    cout << sy.singleNumber(v) << endl;
    return 0;
}
