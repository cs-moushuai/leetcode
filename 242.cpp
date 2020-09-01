#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if(s.size() != t.size())
        {
            return false;
        }
        map<char, int> menu1, menu2;

        for(size_t i = 0; i < s.size(); i++)
        {
            menu1[s[i]]++;
            menu2[t[i]]++;
        }

        return menu1 == menu2;

    }
};

int main(void)
{
    Solution sy;
    cout << sy.isAnagram("rat", "tar") << endl;

    return 0;
}
