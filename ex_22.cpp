#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution
{
private:
    int limit;
    vector<string> res;
    void dfs(string &one, int left, int right)
    {
        if (left == limit && right == limit)
        {
            res.emplace_back(one);
            return;
        }
        if (left < limit)
        {
            one += '(';
            dfs(one, left + 1, right);
            one.pop_back();
        }
        if (right < limit && right < left)
        {
            one += ')';
            dfs(one, left, right + 1);
            one.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n)
    {
        limit = n;
        string one("(");
        dfs(one, 1, 0);

        return res;
    }
};

int main(void)
{
    Solution sy;
    auto res = sy.generateParenthesis(3);

    return 0;
}
