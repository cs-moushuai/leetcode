#include <algorithm>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res;
        int len = strs.size();
        if (len == 0)
            return "";
        int min_len = INT8_MAX;
        for (auto &i : strs)
        {
            int tmp = i.size();
            if (tmp < min_len)
                min_len = tmp;
        }
        for (int j = 0; j < min_len; ++j)
        {
            char c = strs[0][j];
            bool flag = true;
            for (int i = 1; i < len; ++i)
            {
                if (c != strs[i][j])
                    flag = false;
            }
            if (!flag)
                return res;
            res += c;

        }
        return res;
    }
};

int main(void)
{

    Solution sy;
    vector<string> s = {"filx", "fila", "filb"};

    cout << sy.longestCommonPrefix(s) << endl;

    return 0;
}
