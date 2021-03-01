#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

struct  Compare
{
    bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second < rhs.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> menu;
        for (const auto &i : nums)
        {
            ++menu[i];
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pri;
        for (const auto &i : menu)
        {
            pri.push(i);
        }

        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            auto tmp = pri.top();
            pri.pop();
            res.push_back(tmp.first);
        }
        return res;
    }
};


class Solution2
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> menu;
        for (const auto &i : nums)
        {
            ++menu[i];
        }
        vector<pair<int, int>> vec;
        for (const auto &i : menu)
        {
            vec.push_back(i);
        }
        sort(vec.begin(), vec.end(), [] (const pair<int, int> &lhs, const pair<int, int> &rhs)
        {
            return lhs.second > rhs.second;
        });
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(vec[i].first);
        }
        return res;
    }
};

int main(void)
{

    return 0;
}
