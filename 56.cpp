#include <bits/stdc++.h>
#include <iterator>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        int len = intervals.size();
        if (intervals.empty())
            return {};
        else if (len == 1)
            return intervals;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &lhs, const vector<int> &rhs)
        {
            return lhs[0] < rhs[0];
        });

        vector<vector<int>> res;
        int start = intervals[0][0], end = intervals[0][1];
        for (int i = 1; i < len; ++i)
        {
            if (end < intervals[i][0])
            {
                res.emplace_back(vector<int> {start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
            else
            {
                end = max(end, intervals[i][1]);
            }

        }
        res.emplace_back(vector<int> {start, end});
        return res;
    }
};

int main(void)
{

    return 0;
}
