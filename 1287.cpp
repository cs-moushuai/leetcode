#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int>& arr)
    {
        unordered_map<int, int> menu;
        for_each(arr.begin(), arr.end(), [&menu](int i)
        {
            menu[i]++;
        });
        //for(auto i : menu)
        //{
        //cout << i.first << "," << i.second << endl;
        //}
        int result = 0;
        //menu.size();
        //cout << menu.size() << menu.size() / 4.0 << endl;
        for_each(menu.begin(), menu.end(), [&](pair<int, int> i)
        {
            if(i.second > arr.size() / 4.0)
            {
                result = i.first;
            }

        });

        return result;
    }
};

int main(void)
{
    vector<int> v = {1, 2, 2, 6, 6, 6, 6, 7, 10};
    Solution sy;

    cout << sy.findSpecialInteger(v) << endl;

    return 0;
}
