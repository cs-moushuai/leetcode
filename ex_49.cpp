#include <bits/stdc++.h>
#include <cstdlib>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> menu;
        for (auto &i : strs)
        {
            string key = i;
            sort(key.begin(), key.end());
            menu[key].emplace_back(i);
        }
        vector<vector<string>> res;
        for (auto &i : menu)
        {
            res.emplace_back(i.second);
        }
        return res;
    }
};

int main(void)
{
    Solution sy;
    vector<string> s = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = sy.groupAnagrams(s);

    return 0;
}
