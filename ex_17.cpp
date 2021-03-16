#include <bits/stdc++.h>
#include <climits>
#include <vector>

using namespace std;

class Solution
{
private:
    int len;
    string digits_;
    vector<string> res;
    vector<char> getMap(int num)
    {
        switch(num)
        {
        case '2':
            return {'a', 'b', 'c'};
        case '3':
            return {'d', 'e', 'f'};
        case '4':
            return {'g', 'h', 'i'};
        case '5':
            return {'j', 'k', 'l'};
        case '6':
            return {'m', 'n', 'o'};
        case '7':
            return {'p', 'q', 'r', 's'};
        case '8':
            return {'t', 'u', 'v'};
        case '9':
            return {'w', 'x', 'y', 'z'};
        default:
            return {};
        }
    }
    void dfs(string &path, int pos)
    {
        if (pos == len)
        {
            res.emplace_back(path);
            return;
        }
        auto arr = getMap(digits_[pos]);
        for (auto &i : arr)
        {
            path += i;
            dfs(path, pos + 1);
            path.pop_back();
        }

    }
public:
    vector<string> letterCombinations(string digits)
    {
        len = digits.size();
        if (len == 0)
            return {};
        digits_ = digits;
        string path;
        dfs(path, 0);

        return res;
    }
};

int main(void)
{

    return 0;
}
