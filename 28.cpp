#include <iostream>

using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        unsigned h_length = haystack.length();
        unsigned n_length = needle.length();

        for (size_t i = 0; i < h_length; i++)
        {
            for (size_t j = 0; haystack[i + j] == needle[j]; j++)
            {

                if (j + 1 == n_length)
                {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main(void)
{
    Solution sy;
    cout << sy.strStr("hello", "ll") << endl;

    return 0;
}