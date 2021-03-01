#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<int> menu;
        int l = 0, r = 0;
        int len = 0;
        int size = s.size();
        while (r < size)
        {
            if (!menu.count(s[r]))
            {
                menu.emplace(s[r]);
                len = max(len, r - l + 1);
                ++r;
            }
            else
            {
                menu.erase(s[l]);
                ++l;
            }
        }
        return len;

    }
};

int main(void)
{

    return 0;
}
