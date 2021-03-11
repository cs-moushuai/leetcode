#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class Solution
{
public:
    int numSizeString(string s1, string s2)
    {
        if (s1.length() > s2.length())
        {
            return 0;
        }
        else if (s1.length() == s2.length())
        {
            return s1 > s2 ? 0 : stod(s1);
        }
        else
        {
            return stod(s1);
        }
    }

    int reverse(int x)
    {
        string s = to_string(x);
        bool flag = true;

        auto fHead = [&s, &flag]() {
            if (*s.begin() == '-')
            {
                flag = false;
                return s.begin() + 1;
            }
            return s.begin();
        };
        for (auto head = fHead(), tail = s.end() - 1; head < tail; head++, tail--)
        {
            swap(*head, *tail);
        }

        string max = to_string(INT_MAX);
        string min = to_string(INT_MIN);

        int result = 0;
        if (flag == true) //+
        {
            result = numSizeString(s, max);
        }
        else //-
        {
            result = numSizeString(s, min);
        }

        return result;
    }
};

int main(void)
{
    Solution sy;
    int num;
    cin >> num;
    cout << sy.reverse(num) << endl;
    return 0;
}