#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        auto tail = s.rbegin();

        if (tail == s.rend())
        {
            return 0;
        }
        while (*tail == ' ')
        {
            if (tail == s.rend())
            {
                return 0;
            }

            tail++;
        }

        int length = 0;

        for (; tail != s.rend() && *tail != ' '; tail++, length++)
            ;
        return length;
    }
};

int main(void)
{
    Solution sy;
    cout << sy.lengthOfLastWord("Hello world") << endl;
    return 0;
}