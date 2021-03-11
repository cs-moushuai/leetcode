#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
private:
    unordered_map<char, int> menu;
    unordered_map<char, int> curr;
    bool check()
    {
        for (const auto &i : menu)
        {
            if (curr[i.first] < menu[i.first])
                return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p)
    {
        for (const auto &i : p)
        {
            ++menu[i];
        }
        int l = 0, r = 0;
        int len = s.size();
        vector<int> res;
        int expect = p.size();
        while (r < len)
        {
            ++curr[s[r]];
            ++r;
            while (l < r && check())
            {
                if (r - l == expect)
                {
                    res.emplace_back(l);
                }
                --curr[s[l]];
                ++l;
            }
        }
        return res;
    }
};


class Solution2
{
private:
    unordered_map<char, int> menu;
    unordered_map<char, int> curr;
    bool check()
    {
        return menu == curr;
    }
    bool has()
    {
        for (auto &i : menu)
        {
            auto j = curr.find(i.first);
            if (j != curr.end())
            {
                if (j->second < i.second)
                    return false;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p)
    {
        for (const auto &i : p)
        {
            ++menu[i];
        }
        int l = 0, r = 0;
        int len = s.size();
        vector<int> res;
        while (r < len)
        {
            ++curr[s[r]];
            ++r;
            while (l < r && has())
            {
                if (check())
                {
                    res.emplace_back(l);
                }
                --curr[s[l]];
                if (!curr[s[l]])
                    curr.erase(s[l]);
                ++l;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution sy;
    auto res = sy.findAnagrams("cbaebabacd", "abc");
    for (auto i : res)
    {
        cout << i << " " << endl;
    }

    return 0;
}
