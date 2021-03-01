#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<char, int> ori, menu;
public:
    bool check()
    {
        for (auto i : ori)
        {
            if (i.second > menu[i.first])
            {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        for (const auto &i : t)
        {
            ++ori[i];
        }

        int left = 0, right = -1;
        int min_left = -1, len = INT_MAX;

        while (right < int(s.size()))
        {
            if (ori.find(s[++right]) != ori.end())
            {
                ++menu[s[right]];
            }
            while (check() && left <= right)
            {
                if (right - left + 1 < len)
                {
                    min_left = left;
                    len = right - left + 1;
                }
                if (ori.find(s[left]) != ori.end())
                {
                    --menu[s[left]];
                }
                ++left;
            }
        }
        return min_left == -1 ? string() : s.substr(min_left, len);
    }
};

//class Solution
//{
//public:
//string minWindow(string s, string t)
//{
//map<char, int> menu;
//int min_left = 0, min_right = 0;
//bool first_time = true;
//for (int i = 0; i < s.size(); ++i)
//{
//auto j = t.find(s[i]);
//if (j != std::string::npos)
//{
//if (first_time)
//{
//min_left = i;
//first_time = false;
//}
//else
//{
//min_right = i;
//}
//++menu[s[i]];
//}
//}
//for (auto i : t)
//{
//if (menu[i] == 0)
//{
//return "";
//}
//}
//for (int left = min_left, right = min_right; ; )
//{
//bool flag = false;
//if (menu[s[left]] > 1)
//{
//--menu[s[left]];
//++left;
//flag = true;
//}
//else if (menu[s[left]] == 0)
//{
//++left;
//flag = true;
//}
//if (menu[s[right]] > 1)
//{
//--menu[s[right]];
//--right;
//flag = true;
//}
//else if (menu[s[right]] == 0)
//{
//--right;
//flag = true;
//}
//if (!flag)
//{
//return string(s.begin() + left, s.begin() + right + 1);
//}
//}

//}
//};

int main(void)
{
    Solution sy;
    //cout  << sy.minWindow("ADOBECODEBANC", "ABC") << endl;
    cout  << sy.minWindow("ab", "a") << endl;

    return 0;
}
