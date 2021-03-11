#include <bits/stdc++.h>

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        vector<vector<int>> arr(intervals);
        auto res = find_if(arr.begin(), arr.end(), [&newInterval](vector<int> &lhs)
        {
            if (lhs[0] >= newInterval[0])
                return true;
            return false;
        });
        arr.insert(res, newInterval);
        arr = merge(arr);
        return arr;
    }
};

int main(void)
{

    return 0;
}
